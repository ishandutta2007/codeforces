#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MaxN=310;
const int MaxC=180010;

int n,m;
int a[MaxN][MaxN],b[MaxN][MaxN];
vector<int> p;
pair<int,int> s[MaxC],F[MaxN][MaxN];
int v[MaxN][MaxN];
vector<pair<int,int> > w[MaxN][MaxN];
queue<pair<int,int> > Q;
vector<pair<int,pair<int,int> > > list;

void init()
{
	cin>>n>>m;
	p.push_back(0);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			p.push_back(a[i][j]);
		}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&b[i][j]);
			if (b[i][j]!=-1) p.push_back(b[i][j]);
		}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			a[i][j]=lower_bound(p.begin(),p.end(),a[i][j])-p.begin();
			if (b[i][j]!=-1) b[i][j]=lower_bound(p.begin(),p.end(),b[i][j])-p.begin();
			if (s[a[i][j]]==make_pair(0,0))
				s[a[i][j]]=make_pair(i,j);
			int x=s[a[i][j]].first,y=s[a[i][j]].second;
			++v[x][y];
			if (b[i][j]!=-1)
				w[x][y].push_back(make_pair(i,j));
			F[i][j]=s[a[i][j]];
		}
	int x,y;
	cin>>x>>y;
	Q.push(make_pair(x,y));
}

pair<int,int> father(int x,int y)
{
	return (F[x][y]==make_pair(x,y))?F[x][y]:F[x][y]=father(F[x][y].first,F[x][y].second);
}

int getabs(int x)
{
	return (x>=0)?x:-x;
}

int getdis(int x,int y)
{
	int p=max(getabs(x),getabs(y));
	if (!p) return 1;
	int t=(2*p-1)*(2*p-1);
	if (x==-p&&y>-p) return t+y+p;
	t+=2*p;
	if (y==p&&x>-p) return t+x+p;
	t+=2*p;
	if (x==p&&y<p) return t+p-y;
	t+=2*p;
	return t+p-x;
}

void work()
{
	long long ans=0;
	while (!Q.empty())
	{
		int x=Q.front().first,y=Q.front().second;
		Q.pop();
		int c=b[x][y];
		if (c==-1) continue;
		b[x][y]=-1;
		pair<int,int> p=father(x,y);
		int d=a[p.first][p.second];
		if (d==c||!d) continue;
		ans+=v[s[d].first][s[d].second];
		list.clear();
		for (int i=0;i<w[s[d].first][s[d].second].size();++i)
		{
			int tx=w[s[d].first][s[d].second][i].first,ty=w[s[d].first][s[d].second][i].second;
			if (b[tx][ty]==-1) continue;
			int dis=getdis(tx-x,ty-y);
			list.push_back(make_pair(dis,w[s[d].first][s[d].second][i]));
		}
		w[s[d].first][s[d].second].clear();
		sort(list.begin(),list.end());
		for (int i=0;i<list.size();++i)
			Q.push(list[i].second);
		if (s[c]==make_pair(0,0))
		{
			s[c]=s[d];
			a[s[d].first][s[d].second]=c;
		}
		else
		{
			F[s[d].first][s[d].second]=s[c];
			v[s[c].first][s[c].second]+=v[s[d].first][s[d].second];
			v[s[d].first][s[d].second]=0;
		}
		s[d]=make_pair(0,0);
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}