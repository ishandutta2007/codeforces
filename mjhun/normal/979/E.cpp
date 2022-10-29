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

int n,pp;
int c[64];
ll f[64][64][64][2]; // cantidad de formas de hacerlo par
ll p2[1<<16];

int main(){
	p2[0]=1;
	fore(i,1,1<<16)p2[i]=p2[i-1]*2%MOD;
	scanf("%d%d",&n,&pp);
	fore(i,0,n)scanf("%d",c+i);
	f[0][0][0][0]=1;
	fore(i,0,n){
		fore(j,0,i+1)fore(k,0,i+1)fore(p,0,2){
			if(!f[i][j][k][p])continue;
			if(c[i]==0||c[i]<0){ // me importa los k
				// res par (#impar de los k)
				if(k)f[i+1][j][k][p]+=f[i][j][k][p]*p2[i-1]%MOD,f[i+1][j][k][p]%=MOD;

				// res impar (#par de los k)
				ll t=p2[i-k];
				if(k)t=t*p2[k-1]%MOD;
				f[i+1][j+1][k][p^1]+=f[i][j][k][p]*t%MOD;f[i+1][j+1][k][p^1]%=MOD;
			}
			if(c[i]==1||c[i]<0){ // me importa los j

				// res par (#impar de los j)
				if(j)f[i+1][j][k][p]+=f[i][j][k][p]*p2[i-1]%MOD,f[i+1][j][k][p]%=MOD;

				// res impar (#par de los j)
				ll t=p2[i-j];
				if(j)t=t*p2[j-1]%MOD;
				f[i+1][j][k+1][p^1]+=f[i][j][k][p]*t%MOD;f[i+1][j][k+1][p^1]%=MOD;
			}
		}
	}
	ll r=0;
	fore(i,0,n+1)fore(j,0,n+1)r+=f[n][i][j][pp],r%=MOD;
	printf("%lld\n",r);

	//r=0;
	//fore(i,0,n+1)fore(j,0,n+1)r+=f[n][i][j][pp^1],r%=MOD;
	//printf(" %lld\n",r);
	return 0;
}