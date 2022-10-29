#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n;ll l;
ll c[32];

int main(){
	scanf("%d%lld",&n,&l);
	fore(i,0,n)scanf("%lld",c+i);
	fore(i,n,32)c[i]=1LL<<61;
	fore(i,1,32)c[i]=min(c[i],2*c[i-1]);
	for(int i=30;i>=0;--i)c[i]=min(c[i],c[i+1]);
	ll s=0,r=1LL<<61;
	for(int i=31;i>=0;--i){
		if((l>>i)&1)s+=c[i];
		r=min(r,s+c[i]);
	}
	r=min(r,s);
	printf("%lld\n",r);
	return 0;
}