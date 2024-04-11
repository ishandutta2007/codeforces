#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll n;int m;
ll a[8]; // mios
ll b[8]; // del otro
ll s[8]; // problem score

ll q[128]; // cant que resolvieron

ll score(ll q, ll n){
	if(q*32<=n)return 3000;
	if(q*16<=n)return 2500;
	if(q*8<=n)return 2000;
	if(q*4<=n)return 1500;
	if(q*2<=n)return 1000;
	return 500;
}

ll sc(ll *a){
	ll r=0;
	fore(i,0,m){
		if(a[i]>=0){
			r+=s[i]-s[i]*a[i]/250;
		}
	}
	return r;
}

bool can(ll k){
	bool r;
	fore(i,0,m){
		ll qq=q[i];
		if(b[i]>=0&&a[i]>=0&&b[i]<a[i])qq+=k;
		s[i]=score(qq,n+k);
	}
	ll sa=sc(a);
	ll sb=sc(b);
	return sa>sb;
}

int main(){
	scanf("%lld",&n);m=5;
	fore(i,0,m){
		scanf("%lld",a+i);
		if(a[i]>=0)q[i]++;
	}
	fore(i,0,m){
		scanf("%lld",b+i);
		if(b[i]>=0)q[i]++;
	}
	fore(j,0,n-2){
		fore(i,0,m){
			ll k;
			scanf("%lld",&k);
			if(k>=0)q[i]++;
		}
	}
	ll s=0;
	while(s<=2000000&&!can(s))s++;
	if(s>2000000)puts("-1");
	else printf("%lld\n",s);
	return 0;
}