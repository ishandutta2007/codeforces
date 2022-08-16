#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1000010;
const int MOD=1000000007;
const long long P=500000004;

int n,k;
char s[MaxN];
int sum[MaxN],Lk[MaxN],Rk[MaxN],Ls[MaxN],Rs[MaxN],FL[MaxN],FR[MaxN],L[MaxN][2],R[MaxN][2];
int GL[MaxN],GR[MaxN];

int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for (int i=1;i<=n;++i) sum[i]=(s[i]=='X');
	for (int i=Lk[0]=1;i<=n;++i) Lk[i]=(sum[i])?P*Lk[i-1]%MOD:Lk[i-1];
	for (int i=Rk[0]=1;i<=n;++i) Rk[i]=(sum[i])?2*Rk[i-1]%MOD:Rk[i-1];
	for (int i=1;i<=n;++i)
		Ls[i]=(s[i]!='W')?Ls[i-1]+1:0;
	if (s[1]!='W') L[1][1]=1;
	if (s[1]!='B') L[1][0]=1;
	if (k==1) L[1][1]=0;
	L[0][0]=1;
	for (int i=2;i<=n;++i)
	{
		if (s[i]!='B')
			L[i][0]=(L[i-1][0]+L[i-1][1])%MOD;
		if (s[i]!='W')
		{
			L[i][1]=(L[i-1][0]+L[i-1][1])%MOD;
			if (i>=k&&Ls[i]>=k) L[i][1]-=L[i-k][0];
			L[i][1]=(L[i][1]+MOD)%MOD;
		}
	}
	for (int i=k;i<=n;++i)
		if (Ls[i]>=k) FL[i]=L[i-k][0];
	for (int i=1;i<=n;++i)
		GL[i]=(long long)FL[i]*Lk[i]%MOD;
	for (int i=n;i>=1;--i)
		Rs[i]=(s[i]!='B')?Rs[i+1]+1:0;
	if (s[n]!='W') R[n][1]=1;
	if (s[n]!='B') R[n][0]=1;
	if (k==1) R[n][0]=0;
	R[n+1][1]=1;
	for (int i=n-1;i>=1;--i)
	{
		if (s[i]!='W')
			R[i][1]=(R[i+1][0]+R[i+1][1])%MOD;
		if (s[i]!='B')
		{
			R[i][0]=(R[i+1][0]+R[i+1][1])%MOD;
			if (i<=n-k+1&&Rs[i]>=k) R[i][0]-=R[i+k][1];
			R[i][0]=(R[i][0]+MOD)%MOD;
		}
	}
	for (int i=n-k+1;i>=1;--i)
		if (Rs[i]>=k) FR[i]=R[i+k][1];
	for (int i=1;i<=n;++i)
		GR[i]=(long long)FR[i]*Rk[i-1]%MOD;
	long long p=0;
	for (int i=1;i<=n;++i) p=(p+GR[i])%MOD;
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		p-=GR[i];
		if (p<0) p+=MOD;
		ans=(ans+GL[i]*p)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}