#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=40;

int n,m;
char s[MaxN][MaxN];
int tot,f[MaxN][MaxN];
vector<pair<int,int> > v[MaxN];
int c[MaxN],p[MaxN][MaxN];
int ans;

void solve(int x,int k)
{
	if (k==15)
	{
		memset(p,0,sizeof(p));
		for (int i=1;i<=28;++i)
		{
			if (p[c[f[v[i][0].first][v[i][0].second]]][c[f[v[i][1].first][v[i][1].second]]])
				return;
			p[c[f[v[i][0].first][v[i][0].second]]][c[f[v[i][1].first][v[i][1].second]]]=1;
			p[c[f[v[i][1].first][v[i][1].second]]][c[f[v[i][0].first][v[i][0].second]]]=1;
		}
		if (++ans==1)
		{
			for (int i=1;i<=n;++i)
				for (int j=1;j<=m;++j)
				{
					if (s[i][j]=='.') continue;
					s[i][j]=c[f[i][j]]+'0'-1;
				}
		}
		return;
	}
	if (c[k])
	{
		solve(x,k+1);
		return;
	}
	c[k]=x;
	for (int i=k+1;i<=14;++i)
		if (!c[i])
		{
			c[i]=x;
			solve(x+1,k+1);
			c[i]=0;
		}
	c[k]=0;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>s[i]+1;
		for (int j=1;j<=m;++j)
			if (s[i][j]!='.')
			{
				if (!f[i][j])
					f[i][j]=f[i][j+1]=f[i+1][j]=f[i+1][j+1]=++tot;
				v[(s[i][j]>='a')?s[i][j]-'a'+1:s[i][j]-'A'+27].push_back(make_pair(i,j));
			}
	}
	solve(1,1);
	cout<<ans*5040<<endl;
	for (int i=1;i<=n;++i)
		cout<<s[i]+1<<endl;
	return 0;
}