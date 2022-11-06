#include<bits/stdc++.h>
#define mod 10007
#define N 205
using namespace std;

int n,m,cnt,tot,dp[N][N][N],g[N<<1][N<<1]; char s[N];
struct matrix{ int p[N<<1][N<<1]; }a,b;
void operator *=(matrix &x,const matrix y){
	int i,j,k; memset(g,0,sizeof(g));
	for (i=1; i<=tot; i++)
		for (j=i; j<=tot; j++)
			for (k=j; k<=tot; k++) g[i][k]=(g[i][k]+x.p[i][j]*y.p[j][k])%mod;
	swap(x.p,g);
}
void ksm(matrix x,int y){
	int i,j;
	for (i=1; i<=tot; i++)
		for (j=1; j<=tot; j++) b.p[i][j]=(i==j);
	for (; y; y>>=1,x*=x) if (y&1) b*=x;
}
int main(){
	scanf("%s%d",s+1,&m);
	n=strlen(s+1); m+=n;
	int i,j,k;
	for (i=1; i<=n; i++){
		dp[i][i][0]=1;
		if (i<n && s[i]==s[i+1]) dp[i][i+1][0]=1;
	}
	for (i=n-1; i; i--)
		for (j=(s[i]==s[i+1])?i+2:i+1; j<=n; j++)
			if (s[i]==s[j])
				for (k=0; k<=n; k++) dp[i][j][k]=dp[i+1][j-1][k];
			else
				for (k=1; k<=n; k++) dp[i][j][k]=(dp[i][j-1][k-1]+dp[i+1][j][k-1])%mod;
	int ans=0;
	cnt=n+1>>1;
	for (i=1; i<n; i++){ a.p[i][i]=24; a.p[i][i+1]=1; }
	for (i=n; i<n+cnt; i++){ a.p[i][i]=25; a.p[i][i+cnt]=a.p[i-1][i]=1; }
	tot=n+(cnt<<1)-1;
	for (i=n+cnt; i<=tot; i++) a.p[i][i]=26;
	ksm(a,m-1>>1); a*=b;
	for (i=0; i<n; i++){
		j=n-i-1>>1; k=a.p[n-i][n+cnt+j];
		if ((m&1) && !(n-i&1)) k=(k-b.p[n-i][n+j]+mod)%mod;
		ans=(ans+dp[1][n][i]*k)%mod;
	}
	printf("%d\n",ans);
	return 0;
}