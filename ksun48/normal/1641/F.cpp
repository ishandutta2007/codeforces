/**
 *    author:  tourist
 *    created: 23.02.2022 14:47:30       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// code below from https://www.codechef.com/viewsolution/12429578

#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

const double _0=1e-10;
struct pos{
	double x,y;
	pos operator+(pos w){return (pos){x+w.x,y+w.y};}
	pos operator-(pos w){return (pos){x-w.x,y-w.y};}
	pos operator*(double k){return (pos){x*k,y*k};}
	double abs(){return sqrt(x*x+y*y);}
	double atan2(){return ::atan2(y,x);}
	bool operator<(pos w)const{return x<w.x;}
}ps[50007],ps2[50007];
double _c=cos(0.937),_s=sin(0.937);
void mins(double&a,double b){if(a>b)a=b;}
struct dir{
	double d;int t;
	bool operator<(dir w)const{return d<w.d;}
}ds[100007];
const double pi=acos(-1),_2pi=pi*2;
double fix(double x){
	while(x<0)x+=_2pi;
	while(x>=_2pi)x-=_2pi;
	return x;
}
void Solve(vector<pair<double, double>> PTS, int m, double& ans){
        int n = (int) PTS.size();
	for(int i=1;i<=n;++i){
		double x,y;
	        x = PTS[i - 1].first;
	        y = PTS[i - 1].second;
		ps[i]=ps2[i]=(pos){_c*x+_s*y,-_s*x+_c*y};
	}
	srand(n+m+2571);
	std::random_shuffle(ps+1,ps+n+1);
	for(int i=1;i<=n;++i)std::swap(ps[rand()%n+1],ps[rand()%n+1]);
	std::sort(ps2+1,ps2+n+1);
	for(int i=1;i<=n;++i){
		double L=0,R=ans,M;
		bool ed=0;
		while((R-L)/max(1.0, L)>_0){
			if (L < 1 && R > 1) M=1; else
			if (L < 1) M = (L+R)/2;
			else M = sqrt(L*R);
			if(!ed)M=R,ed=1;
			int ls=std::lower_bound(ps2+1,ps2+n+1,(pos){ps[i].x-M*2-_0,0})-ps2;
			int rs=std::upper_bound(ps2+1,ps2+n+1,(pos){ps[i].x+M*2+_0,0})-ps2;
			int c=0,ab=0;
			if(rs-ls>=m){
				int dp=0;
				for(int j=ls;j<rs;++j){
					pos p=ps2[j]-ps[i];
					double d=p.abs(),r=M*2;
					if(d>r)continue;
					if(d<_0){
						++c;
						continue;
					}
					double a=p.atan2(),b=asin(sqrt(1-d*d/(r*r)));
					double la=fix(a-b),ra=fix(a+b);
					if(la>ra)++c;
					ds[dp++]=(dir){la,1};
					ds[dp++]=(dir){ra,-1};
				}
				std::sort(ds,ds+dp);
				if(c>=m)ab=1;
				for(int j=0;j<dp;++j){
					c+=ds[j].t;
					if(c>=m)ab=1;
				}
			}
			if(ab)R=ans=M;
			else L=M;
		}
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
	  x[i] += 1e8;
	  y[i] += 1e8;
    }
    double ans = 1e9;
	for(int R = 2; R < ans; R = 1 + R * 1.1){
		bool works = false;
		map<pair<int,int>,int> freq;
		for(int i = 0; i < n; i++){
			if(i >= l) freq[{x[i-l] / R, y[i-l] / R}]--;
			pair<int,int> key = {x[i] / R, y[i] / R};
			freq[key]++;
			if(freq[key] >= k){
				works = true;
				break;
			}
		}
		if(works){
			ans = double(R) / sqrt(double(2));
			break;
		}
	}
    for (int i = 0; i < n; i++) {
	  x[i] -= 1e8;
	  y[i] -= 1e8;
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
//      if (i % 1000 == 0) debug(i, ans, clock());
      s.emplace(x[i], y[i]);
      if (i - l >= 0) {
        s.erase(make_pair(x[i - l], y[i - l]));
      }
      vector<pair<double, double>> ps;
      auto it = s.lower_bound(make_pair((int) (x[i] - 2 * ans - 2), (int) -1e9));
      while (it != s.end()) {
        auto p = *it;
        long long dx = p.first - x[i];
        if (dx > 2 * ans + 2) {
          break;
        }
        dx = abs(dx);
        long long dy = abs(p.second - y[i]);
        if (dx * dx + dy * dy < 4 * ans * ans) {
          ps.emplace_back(p.first, p.second);
        }
        ++it;
      }
      if(ps.size() >= k) Solve(ps, k, ans);
    }
    cout << fixed << setprecision(17) << ans << '\n';
  }
  return 0;
}