#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1))%mod;
}

int u[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll p,k;
	cin>>p>>k;
	if (k==0){
		cout<<pot(p, p-1)<<endl;
	}
	else if(k==1){
		cout<<pot(p, p)<<endl;
	}
	else{
		ll f=0;
		for (ll i=1;i<p;i++){
			if (!u[i]){
				f++;
				ll x=i;
				while (1){
					u[x]=1;
					x=(k*x)%p;
					if (u[x]) break;
				}
			}
		}
		cout<<pot(p, f)<<endl;
	}
}