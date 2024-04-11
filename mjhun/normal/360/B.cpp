#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll x[2048];
int n,k;
int f[2048];

int doit(ll w){
	for(int i=n-1;i>=0;--i){
		f[i]=n-1-i;
		fore(j,i+1,n)if(abs(x[j]-x[i])<=(j-i)*w)f[i]=min(f[i],j-i-1+f[j]);
	}
	int r=f[0];
	fore(i,1,n)r=min(r,i+f[i]);
	return r;
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%lld",x+i);
	ll s=0,e=1LL<<31;
	while(e-s>1){
		ll m=(s+e)/2;
		if(doit(m-1)<=k)e=m;
		else s=m;
	}
	printf("%lld\n",s);
	return 0;
}