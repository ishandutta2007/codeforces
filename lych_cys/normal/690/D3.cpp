#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000003
#define N 105
using namespace std;

int cnt,n,m,f[N];
struct matrix{ int p[N][N]; }a,b;
matrix operator *(matrix x,matrix y){
	matrix z;int i,j,k;
	for (i=0; i<=n; i++)
		for (j=0; j<=n; j++)
			for (z.p[i][j]=0,k=0; k<=n; k++) z.p[i][j]=(z.p[i][j]+(ll)x.p[i][k]*y.p[k][j])%mod;
	return z;
}
int ksm(int x,int y){
	int t=1; for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) t=(ll)t*x%mod;
	return t;
}
int main(){
	scanf("%d%d%d",&cnt,&n,&m); int i,j;
	a.p[0][n-1]=a.p[0][n]=b.p[n][n]=1;
	for (i=1; i<=n; i++){
		b.p[i][i-1]=1;
		b.p[n-i][n]=ksm(m,i);
	}
	for (; cnt; cnt>>=1,b=b*b) if (cnt&1) a=a*b; printf("%d\n",a.p[0][n]);
	//f[0]=1; f[1]=1; cnt++;
	//for (i=2; i<=cnt; i++){
	//	f[i]=f[i-1];
	//	for (j=1; j<=n && i-j-1>=0; j++) f[i]=(f[i]+(ll)f[i-j-1]*ksm(m,j))%mod;
	//}
	return 0;
}