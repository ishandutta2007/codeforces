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
#define MOD 1000000007
using namespace std;
typedef long long ll;

int f[64][64][2];
int c[64][64];
int nn,kk;

int main(){
	fore(i,0,64){
		c[i][0]=c[i][i]=1;
		fore(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
	scanf("%d%d",&nn,&kk);
	f[0][0][1]=f[1][0][0]=1;
	fore(n,2,nn+1)fore(k,0,min(kk,n/2)+1)fore(d,0,2){
		int& r=f[n][k][d];
		if(d==0){
			fore(n0,0,n)fore(k0,0,k+1){
				r+=1LL*c[n-1][n0]*f[n0][k0][1]%MOD*f[n-1-n0][k-k0][1]%MOD;
				r%=MOD;
			}
		}
		else {
			fore(n0,0,n)fore(k0,0,k){
				r+=1LL*c[n-1][n0]*f[n0][k0][0]%MOD*f[n-1-n0][k-1-k0][0]%MOD;
				r%=MOD;
				r+=1LL*c[n-1][n0]*f[n0][k0][0]%MOD*f[n-1-n0][k-1-k0][1]%MOD;
				r%=MOD;
				r+=1LL*c[n-1][n0]*f[n0][k0][1]%MOD*f[n-1-n0][k-1-k0][0]%MOD;
				r%=MOD;
			}
		}
		r=1LL*r*((MOD+1)/2)%MOD;
		if(n<nn)r=1LL*r*n%MOD;
	}
	printf("%d\n",(f[nn][kk][0]+f[nn][kk][1])%MOD);
	return 0;
}