#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int h[100];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll np=1;
	ll nc=7;
	ll mp=1;
	ll mc=7;
	while (nc<n) {
		nc*=7;
		np++;
	}
	while (mc<m){
		mc*=7;
		mp++;
	}
	if (mp+np>7) {
		cout<<0<<endl;
		return 0;
	}
	ll v=0;
	for (ll i=0;i<n;i++){
		ll x=i;
		for (int a=0;a<np;a++){
			h[x%7]++;
			x/=7;
		}
		for (ll j=0;j<m;j++){
			x=j;
			for (int a=0;a<mp;a++){
				h[x%7]++;
				x/=7;
			}
			int f=0;
			for (int a=0;a<7;a++){
				if (h[a]>1) f=1;
			}
			if (!f) v++;
			x=j;
			for (int a=0;a<mp;a++){
				h[x%7]--;
				x/=7;
			}
		}
		x=i;
		for (int a=0;a<np;a++){
			h[x%7]--;
			x/=7;
		}
	}
	cout<<v<<endl;
}