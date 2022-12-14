#include<bits/stdc++.h>
using namespace std;
const int maxn=30000000;
int n,a[111111],m,pos,arr[111111],cnt,pro,fuck[111111],crt,pre[111111],path[111111];
int dp[111111];
char s[11],ans[111111];
bool f1,f2,f3;
void solve(int l,int r)
{
	if (l>=r) return;
	crt=0;
	for (int i=l;i<=r;i++)
	{
		if (a[i]>1) fuck[++crt]=i;
	}
	pro=1;
	for (int i=l;i<=r;i++)
	{
		pro*=a[i];
		if (pro>maxn)
		{
			for (int j=fuck[1];j<fuck[crt];j++) ans[j]='*';
			return;
		}
	}
	if (!crt) return;
	pre[0]=1;
	for (int i=1;i<=crt;i++) pre[i]=pre[i-1]*a[fuck[i]];
	for (int i=1;i<=crt;i++)
	{
		dp[i]=-1e9;
		for (int j=0;j<i;j++)
		{
			if (dp[j]+fuck[j+1]-fuck[j]-1+pre[i]/pre[j]>dp[i])
			{
				dp[i]=dp[j]+fuck[j+1]-fuck[j]-1+pre[i]/pre[j];
				path[i]=j;
			}
		}
	}
	for (int i=crt;i;i=path[i])
	{
		for (int j=fuck[path[i]+1];j<fuck[i];j++) ans[j]='*';
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%s",s);
	m=strlen(s);
	for (int i=0;i<m;i++)
	{
		if (s[i]=='+') f1=1;
		if (s[i]=='-') f2=1;
		if (s[i]=='*') f3=1;
	}
	if (f2 && !f1 && !f3)
	{
		for (int i=1;i<n;i++)
		{
			printf("%d-",a[i]);
		}
		printf("%d\n",a[n]);
	}
	else if (!f1 && f2 && f3)
	{
		pos=n+1;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0) 
			{
				pos=i;
				break;
			}
		}
		for (int i=1;i<pos-1;i++)
		{
			printf("%d*",a[i]);
		}
		if (pos<=n && pos>1)
		{
			printf("%d-",a[pos-1]);
		}
		for (int i=pos;i<n;i++)
		{
			printf("%d*",a[i]);
		}
		printf("%d\n",a[n]);
	}
	else
	{
		if (!f1)
		{
			for (int i=1;i<n;i++)
			{
				printf("%d*",a[i]);
			}
			printf("%d\n",a[n]);
		}
		else if (!f3)
		{
			for (int i=1;i<n;i++)
			{
				printf("%d+",a[i]);
			}
			printf("%d\n",a[n]);
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				if (!a[i]) 
				{
					arr[++cnt]=i;
				}
			}
			for (int i=1;i<n;i++) ans[i]='+';
			solve(1,arr[1]-1);
			for (int i=1;i<cnt;i++)
			{
				solve(arr[i]+1,arr[i+1]-1);
			}
			solve(arr[cnt]+1,n);
			for (int i=1;i<n;i++)
			{
				printf("%d%c",a[i],ans[i]);
			}
			printf("%d\n",a[n]);
		}
	}
	return 0;
}