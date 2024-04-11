#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=105,mod=998244353;
int n,m,k;
bool w[MAXN][MAXN];
int d[MAXN];
struct Matrix{
	int a[MAXN*2][MAXN*2];
	int* operator [](int x){
		return a[x];
	}
}mul[15];
Matrix operator *(Matrix a,Matrix b){
	static Matrix c;
	for(int i=1; i<=n*2; i++)
		for(int j=1; j<=n*2; j++){
			c[i][j]=0;
			for(int k=1; k<=n*2; k++)
				c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%mod;
		}
	return c;
}
struct Array{
	int a[MAXN*2];
	int& operator [](int x){
		return a[x];
	}
}f;
Array operator *(Array a,Matrix b){
	static Array c;
	for(int j=1; j<=n*2; j++){
		c[j]=0;
		for(int k=1; k<=n*2; k++)
			c[j]=(c[j]+1ll*a[k]*b[k][j])%mod;
	}
	return c;
}
int ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k==1) puts("0"),exit(0);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		w[u][v]=w[v][u]=1;
		d[u]++;
		d[v]++;
	}
	for(int i=1; i<=n; i++){
		mul[0][i+n][i]=1;
		mul[0][i][i+n]=(1+mod-d[i])%mod;
		for(int j=1; j<=n; j++)
			mul[0][i+n][j+n]=w[i][j];
	}
	for(int i=1; 1<<i<=k-2; i++)
		mul[i]=mul[i-1]*mul[i-1];
	for(int i=1; i<=n; i++){
		memset(&f,0,sizeof(Array));
		f[i]=1;
		for(int j=1; j<=n; j++)
			f[j+n]=w[i][j];
		for(int j=0; 1<<j<=k-2; j++)
			if(1<<j&k-2) f=f*mul[j];
		ans=(ans-f[i]+mod)%mod;
		f=f*mul[0];
		ans=(ans+f[i+n])%mod;
	}
	printf("%d\n",ans);
	return 0;
}