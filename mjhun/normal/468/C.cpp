#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll sd(ll x){
	ll r=0;
	while(x)r+=x%10,x/=10;
	return r;
}

ll g[16];

ll f(ll x){
	if(x<=0)return 0;
	ll r=45*(x/10);
	r+=g[x%10];
	r+=(sd(x)-x%10)*(x%10+1);
	r+=f(x/10-1)*10;
	return r;
}

int main(){
	g[0]=0;
	fore(i,1,10)g[i]=g[i-1]+i;
	ll a;
	scanf("%lld",&a);
	ll s=1,e=100000000000000000LL;
	while(e-s>1){
		ll m=(s+e)/2;
		if(f(m-1)>=a)e=m;
		else s=m;
	}
	ll i=0,j=s,fi=0,fj=f(s);
	while(fj-fi!=a){
		if(fj>a+fi)fi+=sd(++i);
		else fj+=sd(++j);
	}
	assert(f(j)-f(i)==a);
	printf("%lld %lld\n",i+1,j);
	return 0;
}