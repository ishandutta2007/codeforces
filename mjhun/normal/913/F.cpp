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
#define MOD 998244353
using namespace std;
typedef long long ll;

int mul(int a, int b){return 1LL*a*b%MOD;}

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=mul(r,a);
		e>>=1;
		a=mul(a,a);
	}
	return r;
}

int inv(int a){return pm(a,MOD-2);}

int n,p;
int dp[2048][2048];
int pe[2048],pi[2048];
int q[2048]; // prob sc
int r[2048];

int f(int n, int m){ // n 1s, m 0s
	if(dp[n][m]>=0)return dp[n][m];
	int r=0;
	if(n)r+=mul(f(n-1,m),pe[m]);
	if(m)r+=mul(f(n,m-1),pi[n]),r%=MOD;
	return dp[n][m]=r;
}

int main(){
	memset(dp,-1,sizeof(dp));dp[0][0]=1;
	int a,b;
	scanf("%d%d%d",&n,&a,&b);
	p=mul(a,inv(b));
	pe[0]=pi[0]=1;
	fore(i,1,2048)pe[i]=mul(pe[i-1],p),pi[i]=mul(pi[i-1],MOD+1-p);
	r[1]=0;q[1]=1;r[2]=1;q[2]=0;
	fore(i,3,n+1){
		fore(j,1,i){
			int z=mul(f(j,i-j),q[j]);
			q[i]+=z;q[i]%=MOD;
			r[i]+=mul(z,(((j*(i-j)+j*(j-1)/2)%MOD+r[j])%MOD+r[i-j])%MOD);r[i]%=MOD;
		}
		r[i]+=mul(MOD+1-q[i],i*(i-1)/2);r[i]%=MOD;
		r[i]=mul(r[i],inv(q[i]));
		q[i]=MOD+1-q[i];
	}
	printf("%d\n",r[n]);
	return 0;
}