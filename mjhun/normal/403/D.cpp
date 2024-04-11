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

#define MOD 1000000007

int md(int x){return x>=MOD?x-MOD:x;}

int c[1024][1024];
int f[53][1003][1003];
int ff[64];

int main(){
	ff[0]=1;
	fore(i,1,64)ff[i]=1LL*i*ff[i-1]%MOD;
	fore(i,0,1024){
		c[i][0]=c[i][i]=1;
		fore(j,1,i)c[i][j]=md(c[i-1][j-1]+c[i-1][j]);
	}
	fore(i,0,1003)fore(j,0,1003)f[0][i][j]=1;
	fore(i,1,53)for(int j=1001;j>=0;--j)fore(k,0,1003){
		f[i][j][k]=f[i][j+1][k];
		if(j<=k)f[i][j][k]=md(f[i][j][k]+f[i-1][j+1][k-j]);
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,r=0;
		scanf("%d%d",&n,&k);
		if(k>=50){puts("0");continue;}
		fore(m,k,n+1)r=md(r+1LL*c[m-1][k-1]*f[k][0][n-m]%MOD);
		r=1LL*r*ff[k]%MOD;
		printf("%d\n",r);
	}
	return 0;
}