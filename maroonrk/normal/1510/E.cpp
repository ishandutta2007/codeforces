#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int long long
#define rep(i,b) for(int i=0;i<b;i++)
#define repn(i, b) for(int i=1;i<=b;i++)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#define mp make_pair
#define a first
#define b second

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
template<class t>
using vc = vector<t>;
using P=pair<int,int>;

#define SORT(x) sort(x.begin(), x.end())
#define POSL(x, v) lower_bound(x.begin(),x.end(),v)-x.begin()

int n;
double ax, ay;
vc<pair<P, int>>mem[350][19];

void solve(){
	cin >> n >> ax >> ay;
	int m = n/2;
	rep(mask, (1<<m)){
		vc<int>num(m);
		rep(j, m){
			num[j] = 1 - 2 * ( (mask >> j) & 1 );
		}
		int val = 0, bad = 0;
		rep(j, m){
			val += num[j];
			if(val < 0) bad = 1;
		}
		if(bad) continue;
		
		val = 0;
		int area = 0;
		P sum = mp(0, 0);
		int add = 0;
		rep(j, m){
			int lx = n-1-j, rx = n-j;
			int llen = val + num[j], rlen = val;
			
			area += llen + rlen;
			
			if(llen < rlen){
    			rep(a, 100){
    				if(a > llen || a+1 > rlen) break;
    				sum.a += lx*3+2;
    				sum.b += 3*a+1;
    				add ++ ;
    			}
    			rep(a, 100){
    				if(a+1 > llen || a+1 > rlen) break;
    				sum.a += lx*3+1;
    				sum.b += 3*a+2;
    				add ++;
    			}
			}
			else{
			    rep(a, 100){
    				if(a+1 > llen || a > rlen) break;
    				sum.a += lx*3+1;
    				sum.b += 3*a+1;
    				add ++ ;
    			}
    			rep(a, 100){
    				if(a+1 > llen || a+1 > rlen) break;
    				sum.a += lx*3+2;
    				sum.b += 3*a+2;
    				add ++;
    			}
			}
			val += num[j];
		}
		assert(area <= 324);
		assert(add == area);
		mem[area][val].pb(mp(sum, mask));
	//	if(mask == 4) cout <<area<<" "<<val<<" "<<sum<<endl;
	}
	rep(i, 350)rep(j,19) SORT(mem[i][j]);
	
	pair<double, string>zan = mp(1e18, "");
	
	rep(mask, (1<<m)){
		vc<int>num(m);
		rep(j, m){
			num[j] = 1 - 2 * ( (mask >> j) & 1 );
		}
		int val = 0, bad = 0;
		rep(j, m){
			val += num[j];
			if(val < 0) bad = 1;
		}
		if(bad) continue;
		
		val = 0;
		int area = 0;
		P sum = mp(0, 0);
		int add = 0;
		rep(j, m){
			int lx = j, rx = j+1;
			int llen = val, rlen = val + num[j];
			
			area += llen + rlen;
			
			if(llen < rlen){
    			rep(a, 100){
    				if(a > llen || a+1 > rlen) break;
    				sum.a += lx*3+2;
    				sum.b += 3*a+1;
    				add ++ ;
    			}
    			rep(a, 100){
    				if(a+1 > llen || a+1 > rlen) break;
    				sum.a += lx*3+1;
    				sum.b += 3*a+2;
    				add ++;
    			}
			}
			else{
			    rep(a, 100){
    				if(a+1 > llen || a > rlen) break;
    				sum.a += lx*3+1;
    				sum.b += 3*a+1;
    				add ++ ;
    			}
    			rep(a, 100){
    				if(a+1 > llen || a+1 > rlen) break;
    				sum.a += lx*3+2;
    				sum.b += 3*a+2;
    				add ++;
    			}
			}
			val += num[j];
		}
		assert(area <= 324);
		assert(add == area);
		//if(mask == 2) cout <<area<<" "<<val<<" "<<sum<<endl;
		repn(rarea, 324){
			int tx = (int)floor(ax * 3.0 * (double)(area + rarea) + 0.1);
			int ty = (int)floor(ay * 3.0 * (double)(area + rarea) + 0.1);
			P tsum = mp(tx - sum.a, ty - sum.b);
			int v = POSL(mem[rarea][val], mp(tsum, -1LL));
			if(v < mem[rarea][val].size() && mem[rarea][val][v].a == tsum){
				double bx = (double)(tx) / 3.0 / (double)(area + rarea);
				double by = (double)(ty) / 3.0 / (double)(area + rarea);
				
				if(zan.a > sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by))){
					zan.a = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
					string S = "";
					rep(j, m) S.pb((num[j]==1?'(':')'));
					rep(j, m) {
						int f = mem[rarea][val][v].b;
						f = ((f>>(m-1-j))&1);
						
						S.pb((!f?')':'('));
					}
					zan.b = S;
				}
			}
		}
	}
	cout << zan.b << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}