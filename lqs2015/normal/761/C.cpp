#include<iostream>
#include<string>
using namespace std;
string s[55];
int a[55][55],b[55][4],n,m,cnt,ans;
int f[4];
int main()
{
	cin>>n>>m;
	ans=1e9;
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (isdigit(s[i][j])) a[i][j]=1;
			else if (s[i][j]>='a' && s[i][j]<='z') a[i][j]=2;
			else a[i][j]=3;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=3;j++)
		{
			b[i][j]=1e9;
			for (int k=0;k<m;k++)
			{
				if (a[i][k]==j) b[i][j]=min(b[i][j],min(k,m-k));
			}
		}
	}	
	for (int i=1;i<=n;i++) 
	{
		if (!f[a[i][0]]) cnt++;
		f[a[i][0]]++;
	}
	if (cnt==3)
	{
		cout<<0<<endl;
		return 0;
	}
	else if (cnt==2)
	{
		int aa,flag=0;
		for (int i=1;i<=3;i++)
		{
			if (!f[i]) aa=i;
		}
		for (int i=1;i<=n;i++)
		{
			if (f[a[i][0]]==1)
			{
				for (int j=1;j<=n;j++)
				{
					if (i==j) continue;
					ans=min(ans,b[i][aa]+b[j][a[i][0]]);
				}	
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (f[a[i][0]]==1) continue;
			ans=min(ans,b[i][aa]);
		}
		cout<<ans<<endl;
	}
	else
	{
		int aa,bb;
		if (f[1])
		{
			aa=2;bb=3;
		}
		else if (f[2])
		{
			aa=1;bb=3;
		}
		else
		{
			aa=1;bb=2;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i==j) continue;
				ans=min(ans,b[i][aa]+b[j][bb]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}