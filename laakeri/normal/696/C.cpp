#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll pot(ll x, ll p, ll mod){
	if (p==0) {
		return 1;
	}
	if (p%2==0){
		x=pot(x, p/2, mod);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1, mod))%mod;
}

ll inv(ll x, ll mod){
	return pot(x, mod-2, mod);
}

ll ele[101010];

int k;

ll calc(ll mod){
	ll n=1;
	for (int i=0;i<k;i++){
		n*=(ele[i]%(mod-1));
		n%=(mod-1);
	}
	ll t=pot(2, n+(mod-1)-1, mod)+pot(mod-1, n, mod);
	t%=mod;
	return t;
}

ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>k;
	ll val=1;
	ll lolp=1;
	for (int i=0;i<k;i++){
		cin>>ele[i];
		if (ele[i]>4) val=-1;
		else if(val!=-1) val*=ele[i];
		if (val>4) val=-1;
		
		lolp*=(ele[i]%(mod-1));
		lolp%=(mod-1);
	}
	if (val==1){
		cout<<"0/1"<<endl;
		return 0;
	}
	if (val==2){
		cout<<"1/2"<<endl;
		return 0;
	}
	ll v=calc(mod);
	ll asd=calc(3);
	ll p2=pot(2, lolp+(mod-1)-1, mod);
	if (asd==0){
		cout<<(v*inv(3, mod))%mod<<"/"<<p2<<endl;
	}
	else{
		cout<<v<<"/"<<(p2*inv(3, mod))%mod<<endl;
	}
}