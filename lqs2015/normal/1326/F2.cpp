#include<bits/stdc++.h>
using namespace std;
void FWT1(long long a[],int n)
{
	for (int i=2;i<=(1<<n);i<<=1)
	{
		int p=i>>1;
		for (int j=0;j<(1<<n);j+=i)
		{
			for (int k=j;k<j+p;k++)
			{
				a[k+p]+=a[k];
			}
		}
	}
}
void FWT2(long long a[],int n)
{
	for (int i=2;i<=(1<<n);i<<=1)
	{
		int p=i>>1;
		for (int j=0;j<(1<<n);j+=i)
		{
			for (int k=j;k<j+p;k++)
			{
				a[k]-=a[k+p];
			}
		}
	}
}
int n,mp[22][22],cnt,id[333333],pr,b[22],pcnt[333333],ct,msk,cp,crt;
long long dp[333333][22],a[22][333333],ans[1111],c[333333],res[222222];
char s[22];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<n;j++)
		{
			mp[i][j]=(s[j]=='1');
		}
	}
	for (int i=0;i<n;i++)
	{
		dp[1<<i][i]=1;
	}
	for (int i=1;i<(1<<n)-1;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (!dp[i][j]) continue;
			for (int k=0;k<n;k++)
			{
				if ((i&(1<<k)) || !mp[j][k]) continue;
				dp[i^(1<<k)][k]+=dp[i][j];
			}
		}
	}
	for (int i=1;i<(1<<n);i++)
	{
		pcnt[i]=cnt=__builtin_popcount(i);
		for (int j=0;j<n;j++)
		{
			a[cnt][i]+=dp[i][j];
		}
	}
	for (int i=1;i<=n;i++) FWT1(a[i],n);
	for (int i=0;i<(1<<n);i++)
	{
		if (i%2==0) continue;
		cnt=0;pr=0;
		for (int j=1;j<n;j++)
		{
			if (i&(1<<j))
			{
				b[++cnt]=j-pr;
				pr=j;
			}
		}
		b[++cnt]=n-pr;
		bool flg=0;
		for (int j=2;j<=cnt;j++)
		{
			if (b[j]<b[j-1])
			{
				flg=1;
				break;
			}
		}
		if (!flg) 
		{
			id[i]=++crt;
			for (int j=0;j<(1<<n);j++) c[j]=1;
			for (int j=1;j<=cnt;j++)
			{
				for (int k=0;k<(1<<n);k++) c[k]*=a[b[j]][k];
			}
			for (int j=0;j<(1<<n);j++)
			{
				if ((n-pcnt[j])&1) ans[crt]-=c[j];
				else ans[crt]+=c[j];
			}
		}
	}
	for (int i=0;i<(1<<(n-1));i++)
	{
		cnt=0;ct=1;
		for (int j=0;j<n-1;j++)
		{
			if (!(i&(1<<j))) 
			{
				b[++cnt]=ct;
				ct=1;
			}
			else
			{
				ct++;
			}
		}
		b[++cnt]=ct;
		sort(b+1,b+cnt+1);
		msk=1;cp=0;
		for (int j=1;j<cnt;j++)
		{
			cp+=b[j];
			msk|=(1<<cp);
		}
		res[i]=ans[id[msk]];
	}
	FWT2(res,n-1);
	for (int i=0;i<(1<<(n-1));i++)
	{
		printf("%lld ",res[i]);
	}
	printf("\n");
	return 0;
}