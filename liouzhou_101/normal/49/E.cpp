#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<string>

using namespace std;

const int MaxN=60;
const int INF=1000000000;

string s,t;
vector<pair<int,int> > v[MaxN];

void init()
{
	int n;
	cin>>s>>t>>n;
	while (n--)
	{
		string p;
		cin>>p;
		v[p[0]-'a'].push_back(make_pair(p[3]-'a',p[4]-'a'));
	}
}

bitset<MaxN> F[MaxN][MaxN],G[MaxN][MaxN];

void build(string s,bitset<MaxN> F[MaxN][MaxN])
{
	int n=s.length();
	for (int i=0;i<n;++i)
		F[i][i][s[i]-'a']=1;
	for (int k=1;k<n;++k)
		for (int i=0;i<n;++i)
		{
			int j=i+k;
			if (j>=n) continue;
			for (int x=0;x<26;++x)
				for (int y=0;y<v[x].size();++y)
					for (int k=i;k<j;++k)
						if (F[i][k][v[x][y].first]&&F[k+1][j][v[x][y].second])
							F[i][j][x]=1;
		}
}

int p[MaxN][MaxN];

void work()
{
	build(s,F);
	build(t,G);
	int n=s.length(),m=t.length();
	for (int i=0;i<=n;++i)
		for (int j=0;j<=m;++j)
			p[i][j]=INF;
	p[0][0]=0;
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
			for (int x=-1;x<i;++x)
				for (int y=-1;y<j;++y)
					if ((F[x+1][i]&G[y+1][j]).count())
						p[i+1][j+1]=min(p[i+1][j+1],p[x+1][y+1]+1);
	if (p[n][m]==INF) p[n][m]=-1;
	cout<<p[n][m]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}