#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;

int R;
ld r;

int touch(vector<pair<int, co> >& ps, int x, co t, ld y){
	for (auto pp:ps){
		auto p=pp.S;
		int xx=pp.F;
		if (abs(xx-x)<=2*R){
			if (y<p.Y) return 1;
			if (abs(p-t)<(ld)2*r) return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>R;
	r=(ld)R;
	vector<pair<int, co> > ps;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		ld mi=r;
		ld ma=3e6;
		for (int it=0;it<55;it++){
			ld mid=(mi+ma)/(ld)2;
			if (touch(ps, x, {(ld)x, (ld)mid}, mid)){
				mi=mid;
			}
			else{
				ma=mid;
			}
		}
		cout<<setprecision(15)<<ma<<" ";
		ps.push_back({x, {(ld)x, ma}});
	}
	cout<<endl;
}