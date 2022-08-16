#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1010;

int n,k;
int x[MaxN],y[MaxN];
int d[MaxN][MaxN];
vector<int> p;

void init()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>x[i]>>y[i];
	p.push_back(0);
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			p.push_back(d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
}

vector<int> v[MaxN];
int u[MaxN];

bool DFS(int x,int k)
{
	if (x>n) return true;
	if (u[x]) return DFS(x+1,k);
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!u[*it]++) --k;
	if (k>=0) if (DFS(x+1,k)) return true;
	int tmp=k;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!--u[*it]) ++k;
	++u[x];
	if (--k>=0) if (k>tmp) if (DFS(x+1,k)) return true;
	--u[x];
	return false;
}

bool check(int dis)
{
	for (int i=1;i<=n;++i)
	{
		v[i].clear();
		u[i]=0;
	}
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			if (d[i][j]>dis)
			{
				v[i].push_back(j);
				v[j].push_back(i);
			}
	return DFS(1,k);
}

void work()
{
	int L=0,R=p.size()-1;
	int ans=R;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (check(p[mid]))
		{
			ans=mid;
			R=mid-1;
		}
		else
			L=mid+1;
	}
	check(p[ans]);
	for (int i=1;i<=n;++i)
		if (u[i])
		{
			cout<<i<<" ";
			--k;
		}
	for (int i=1;i<=n;++i)
		if (!u[i]&&k)
		{
			cout<<i<<" ";
			--k;
		}
}

int main()
{
	init();
	work();
	return 0;
}