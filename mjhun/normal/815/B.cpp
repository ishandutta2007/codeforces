#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

ll inv(ll x){
	ll e=MOD-2;
	ll r=1;
	while(e){
		if(e&1)r=(1LL*r*x)%MOD;
		e>>=1;
		x=(1LL*x*x)%MOD;
	}
	return r;
}

int n;
ll x[200005],y[200005];
ll f[200005];

ll c(ll n, ll k){
	ll r=(1LL*f[n]*inv(f[n-k]))%MOD;
	r=(1LL*r*inv(f[k]))%MOD;
	return r;
}

int main(){
	f[0]=1;
	fore(i,1,200005)f[i]=(f[i-1]*i)%MOD;
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",x+i);
	if(n==1){printf("%lld\n",x[0]);return 0;}
	if(n%2){
		fore(i,0,n-1){
			if(i%2==0)y[i]=(x[i]+x[i+1])%MOD;
			else y[i]=(x[i]+MOD-x[i+1])%MOD;
		}
		memcpy(x,y,sizeof(x));
		n--;
	}
	ll r=0;
	if(n%4==0){
		fore(i,0,n){
			ll q=c(n/2-1,i/2);
			if(i%2)q=(MOD-q)%MOD;
			r+=(q*x[i])%MOD;
			r%=MOD;
		}
	}
	else {
		fore(i,0,n){
			ll q=c(n/2-1,i/2);
			r+=(q*x[i])%MOD;
			r%=MOD;
		}
	}
	printf("%lld\n",r);
	return 0;
}