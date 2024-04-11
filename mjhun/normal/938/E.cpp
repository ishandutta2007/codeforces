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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;
#define MOD 1000000007


int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=1LL*r*a%MOD;
		e>>=1;
		a=1LL*a*a%MOD;
	}
	return r;
}
int inv(int a){return pm(a,MOD-2);}
int f[1<<20];
int cc(int n, int k){return 1LL*f[n]*inv(f[k])%MOD*inv(f[n-k])%MOD;}

map<int,int> c;

int main(){
	f[0]=1;
	fore(i,1,1<<20)f[i]=1LL*f[i-1]*i%MOD;
	int n;
	scanf("%d",&n);
	int mx=-1;
	fore(_,0,n){
		int x;
		scanf("%d",&x);
		c[x]++;
		mx=max(mx,x);
	}
	int r=0,s=0;
	for(auto p:c){
		if(p.fst==mx)break;
		//printf("%d %d %d %d\n",p.fst,p.snd,n-s,inv(n-s));
		r+=1LL*p.fst*p.snd%MOD*inv(n-s)%MOD;r%=MOD;
		s+=p.snd;
	}
	printf("%lld\n",1LL*r*f[n]%MOD);
	return 0;
}