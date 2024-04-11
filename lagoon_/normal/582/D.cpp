#include<bits/stdc++.h>
#define re register
const int mod=1e9+7;
const long long B=1e9;
long long A[100100];
int A1[100100],p,al,nb;
long long div()
{
	re long long res=0,x1;
	for(re int i=nb;i;i--)x1=(res*B+A[i])%p,A[i]=(res*B+A[i])/p,res=x1;
	while(nb&&!A[nb])nb--;
	return res;
}
char ss[100100];
int f[4010][2][2],g[4010][2][2];
int main()
{
	re int n;
	scanf("%d%d%s",&p,&al,ss+1);
	n=strlen(ss+1);
	std::reverse(ss+1,ss+n+1);
	for(re int i=1;i*9-8<=n;i++)
	{
		for(re int j=std::min(n,i*9);j>=i*9-8;j--)A[i]=A[i]*10+ss[j]-'0';
		nb=i;
	}
	n=0;
	while(nb)A1[++n]=div();
	std::reverse(A1+1,A1+n+1);
	if(al>n){puts("0");return 0;}
	f[0][0][1]=1;
	for(re int i=1;i<=n;i++)
	{
		memcpy(g,f,sizeof(g));
		memset(f,0,sizeof(f));
		for(re int j=0;j<i;j++)
		{
			f[j][0][0]=((long long)p*(p+1)/2%mod*g[j][0][0]+(long long)p*(p-1)/2%mod*g[j][1][0])%mod;
			f[j+1][1][0]=((long long)p*(p-1)/2%mod*g[j][0][0]+(long long)p*(p+1)/2%mod*g[j][1][0])%mod;
			f[j][0][1]=((long long)(A1[i]+1)*g[j][0][1]+(long long)(p-1-A1[i])*g[j][1][1])%mod;
			f[j+1][1][1]=((long long)A1[i]*g[j][0][1]+(long long)(p-A1[i])*g[j][1][1])%mod;
			f[j][0][0]=(f[j][0][0]+(long long)A1[i]*(A1[i]+1)/2%mod*g[j][0][1]+
			(long long)(2*p-A1[i]-1)*A1[i]/2%mod*g[j][1][1])%mod;
			f[j+1][1][0]=(f[j+1][1][0]+(long long)A1[i]*(A1[i]-1)/2%mod*g[j][0][1]+
			(long long)(2*p-A1[i]+1)*A1[i]/2%mod*g[j][1][1])%mod;
		}
	}
	re int ans=0;
	for(re int i=al;i<=n;i++)ans=((long long)ans+f[i][0][0]+f[i][0][1])%mod;
	printf("%d\n",ans);
}