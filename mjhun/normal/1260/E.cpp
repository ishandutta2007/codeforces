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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,k,z;
int a[1<<18];
ll dp[19][1<<18];

ll f(int k, int i, int s){
	if(k<0)return 0;
	ll& r=dp[k][i];
	if(r>=0)return r;
	r=a[i]+f(k-1,i+1,s+(1<<k));
	if(s>i)r=min(r,f(k,i+1,s));
	return r;
}

int main(){
	scanf("%d",&n);
	while((1<<z)<n)z++;
	fore(i,0,n){
		scanf("%d",a+i);
		if(a[i]<0)k=i;
	}
	fore(i,0,k)a[i]=0;
	fore(i,k,n-1)a[i]=a[i+1];
	reverse(a,a+n-1);
	mset(dp,-1);
	printf("%lld\n",f(z-1,0,0));
	return 0;
}