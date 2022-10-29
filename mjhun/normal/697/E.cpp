#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r*=a,r%=MOD;
		e>>=1;
		a*=a;a%=MOD;
	}
	return r;
}

inline void mmul(ll r[][2], ll a[][2], ll b[][2]){
	ll t[2][2];
	t[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
	t[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
	t[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
	t[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
	r[0][0]=t[0][0];r[0][1]=t[0][1];r[1][0]=t[1][0];r[1][1]=t[1][1];
}

void mexp(ll r[][2], ll a[][2], ll e){
	ll t[2][2],t2[2][2];
	memset(t,0,sizeof(t));
	fore(i,0,2)t[i][i]=1;
	memcpy(t2,a,sizeof(t2));
	while(e){
		if(e&1)mmul(t,t,t2);
		e>>=1;
		mmul(t2,t2,t2);
	}
	memcpy(r,t,sizeof(t));
}

ll x[2][2]={{1,2},{1,0}};

int main(){
	int k;
	ll p=2;
	scanf("%d",&k);
	while(k--){
		ll e;
		scanf("%lld",&e);
		p=pm(p,e);
		mexp(x,x,e);
	}
	ll r=(x[0][0]-x[1][0]+MOD)%MOD;
	r=(r*(MOD+1)/2)%MOD;
	printf("%lld/%lld\n",r,(p*(MOD+1)/2)%MOD);
	return 0;
}