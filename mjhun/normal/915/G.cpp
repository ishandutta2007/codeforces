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
#define MOD 1000000007
#define MAXN 2000005
using namespace std;
typedef long long ll;

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=(1LL*r*a)%MOD;
		e>>=1;
		a=(1LL*a*a)%MOD;
	}
	return r;
}

int n,k,r[MAXN],a[MAXN];
vector<int> d[MAXN];

int main(){
	fore(i,1,MAXN)for(int j=2*i;j<MAXN;j+=i)d[j].pb(i);
	scanf("%d%d",&n,&k);
	fore(i,0,k+1)a[i]=pm(i,n);
	int rr=0;r[1]=1;
	fore(i,2,k+1){
		r[i]=(a[i]+MOD-a[i-1])%MOD;
		for(int z:d[i]){
			r[i]+=MOD-r[z];r[i]%=MOD;
			r[i]+=r[z-1];r[i]%=MOD;
		}
		r[i]+=r[i-1];r[i]%=MOD;
		rr+=r[i]^i;rr%=MOD;
	}
	printf("%d\n",rr);
	return 0;
}