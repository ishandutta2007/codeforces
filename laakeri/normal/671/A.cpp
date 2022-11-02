#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ld ax,ay,bx,by,tx,ty;
	cin>>ax>>ay>>bx>>by>>tx>>ty;
	co a={ax, ay};
	co b={bx, by};
	co t={tx, ty};
	vector<pair<ld, int> > d1;
	vector<pair<ld, int> > d2;
	int n;
	cin>>n;
	ld v=0;
	for (int i=0;i<n;i++){
		ld x,y;
		cin>>x>>y;
		co p={x, y};
		v+=abs(p-t)*(ld)2;
		d1.push_back({abs(p-t)-abs(a-p), i});
		d2.push_back({abs(p-t)-abs(b-p), i});
	}
	sort(d1.rbegin(), d1.rend());
	sort(d2.rbegin(), d2.rend());
	ld vv=1e18;
	for (int i=-1;i<3;i++){
		for (int ii=-1;ii<3;ii++){
			if (i>=0&&i<(int)d1.size()&&ii>=0&&ii<(int)d2.size()){
				if (d1[i].S==d2[ii].S) continue;
			}
			ld tv=v;
			if (i>=0&&i<(int)d1.size()){
				tv-=d1[i].F;
			}
			if (ii>=0&&ii<(int)d2.size()){
				tv-=d2[ii].F;
			}
			if ((i>=0&&i<(int)d1.size())||(ii>=0&&ii<(int)d2.size())) vv=min(vv, tv);
		}
	}
	cout<<setprecision(15)<<vv<<endl;
}