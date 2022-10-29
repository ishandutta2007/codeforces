#include <cassert>
#include <cstdio>
#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll mul(ll a,ll b){
	return (a*b)%MOD;
}

ll sub(ll a,ll b){
	return (a+MOD-b)%MOD;
}

ll add(ll a,ll b){
	return (a+b)%MOD;
}

ll powmod(ll a, int k){
	if(k==0)return 1;
	if(k%2)return mul(a,powmod(a,k-1));
	ll q=powmod(a,k/2);
	return mul(q,q);
}

int n;ll nf;
ll s;
ll f[32];

ll comb(ll m){
	ll r=nf;
	for(int i=0;i<n-1;++i){
		r=mul(r,(m-i)%MOD);
	}
	return r;
}

int main(){
	cin>>n>>s;
	for(int i=0;i<n;++i){
		cin>>f[i];
	}

	nf=1;
	for(int i=2;i<=(n-1);++i){
		nf=mul(nf,i);
	}
	ll a=nf;
	nf=powmod(nf,MOD-2);
	assert(mul(a,nf)==1);
//	cout<<comb(4)<<endl<<comb(5)<<endl<<comb(6)<<endl<<comb(7)<<endl;

	ll r=comb(s+n-1);

	for(int k=1;k<(1<<n);++k){
		ll t=s;
		int c=0;
		for(int i=0;i<n;++i){
			if(k&(1<<i)){
				t-=f[i]+1;
				c++;
			}
		}
		if(t<0)continue;
		if(c%2){
			r=sub(r,comb(t+n-1));
		}
		else {
			r=add(r,comb(t+n-1));
		}
	}

	cout<<r<<endl;
	return 0;
}