#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<bool> a[202][17];
string qz[202],hz[202];
string s,str[202];
int sz,p,u,v,ans,n,m,sze[222];
bool f;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=200;i++)
	{
		for (int j=1;j<=15;j++)
		{
			sz=pow(2,j);
			a[i][j].resize(sz); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		cin>>str[i];
		s=str[i];
		sz=s.size();
		sze[i]=sz;
		for (int j=0;j<15 && j<sz;j++) qz[i]=qz[i]+s[j];
		for (int j=sz-1;j>sz-16 && j>=0;j--) hz[i]=s[j]+hz[i];
		for (int j=0;j<sz;j++)
		{
			p=0;
			for (int k=j;k<j+15 && k<sz;k++)
			{
				p=p*2+(s[k]-'0');
				a[i][k-j+1][p]=1;
			}
		}
	}
	cin>>m;
	while(m--)
	{
		cin>>u>>v;
		n++;
		for (int i=1;i<=15;i++)
		{
			for (int j=0;j<pow(2,i);j++)
			{
				a[n][i][j]=a[u][i][j] || a[v][i][j];
			}
		}
		s=hz[u]+qz[v];
		sz=s.size();
		for (int i=0;i<sz;i++)
		{
			p=0;
			for (int j=i;j<i+15 && j<sz;j++)
			{
				p=p*2+(s[j]-'0');
				a[n][j-i+1][p]=1;
			}
		}
		sze[n]=sze[u]+sze[v];
		if (sze[n]<=100) str[n]=str[u]+str[v];
		qz[n]=qz[u];hz[n]=hz[v];
		if (qz[n].size()<15)
		{
			if (sze[v]<=100)
			{
				for (int i=0;i<str[v].size() && qz[n].size()<15;i++) qz[n]=qz[n]+str[v][i];
			}
			else
			{
				for (int i=0;i<qz[v].size() && qz[n].size()<15;i++) qz[n]=qz[n]+qz[v][i];
			}
		}
		if (hz[n].size()<15)
		{
			if (sze[u]<=100)
			{
				int szz=str[u].size();
				for (int i=szz-1;i>=0 && hz[n].size()<15;i--) hz[n]=str[u][i]+hz[n];
			}
			else
			{
				int szz=hz[u].size();
				for (int i=szz-1;i>=0 && hz[n].size()<15;i--) hz[n]=hz[u][i]+hz[n];
			}
		}
		ans=0;
		for (int i=1;i<=15;i++)
		{
			f=0;
			for (int j=0;j<pow(2,i);j++)
			{
				if (!a[n][i][j]) f=1;
			}
			if (!f) ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}