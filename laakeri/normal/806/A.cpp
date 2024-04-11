#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tcs;
	cin>>tcs;
	for (int tc=0;tc<tcs;tc++){
		ll x,y,p,q;
		cin>>x>>y>>p>>q;
		if (p==q){
			if (x==y){
				cout<<"0\n";
			}
			else{
				cout<<"-1\n";
			}
			continue;
		}
		if (p==0){
			if (x==0){
				cout<<"0\n";
			}
			else{
				cout<<"-1\n";
			}
			continue;
		}
		ll mi=1;
		ll ma=1e9+10;
		ll v=5e18;
		int f=0;
		while (mi<=ma){
			ll mid=(mi+ma)/2;
			ll tx=p*mid;
			ll ty=q*mid;
			if (tx<x||ty<y){
				mi=mid+1;
			}
			else{
				ll as=ty-y;
				if (x+as<tx){
					mi=mid+1;
				}
				else{
					f=1;
// 					cout<<"taa "<<tx<<" "<<ty<<" "<<ty-y<<endl;
					v=min(v, ty-y);
					ma=mid-1;
				}
			}
		}
		assert(f);
		cout<<v<<'\n';
	}
}