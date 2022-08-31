#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=200010;

int n;
int x[MaxN],y[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=2*n;++i)
		scanf("%d%d",&x[i],&y[i]);
}

int found;
int ans[MaxN],v[MaxN],u[MaxN];

int getdis(int x,int y)
{
	int d=abs(v[x]-v[y]);
	return min(d,n-d);
}

void check()
{
	for (int i=1;i<=2*n;++i)
		if (getdis(x[i],y[i])>2) return;
	found=1;
	for (int i=1;i<=n;++i)
		ans[v[i]]=i;
}

void DFS(int k)
{
	if (k>n)
	{
		check();
		return;
	}
	for (int i=1;i<=n;++i)
		if (!u[i])
		{
			u[i]=1;
			v[k]=i;
			DFS(k+1);
			u[i]=0;
		}
}

void work_1()
{
	DFS(1);
	if (found)
	{
		for (int i=1;i<=n;++i)
			printf("%d ",ans[i]);
	}
	else
		puts("-1");
}

map<pii,int> H;
vector<int> d[MaxN],r[MaxN];

void work_2()
{
	for (int i=1;i<=2*n;++i)
	{
		r[x[i]].push_back(y[i]);
		r[y[i]].push_back(x[i]);
	}
	for (int i=1;i<=n;++i)
	{
		if (r[i].size()!=4)
		{
			puts("-1");
			return;
		}
		sort(r[i].begin(),r[i].end());
	}
	for (int i=1;i<=n;++i)
		for (vector<int>::iterator it=r[i].begin();it!=r[i].end();++it)
		{
			int x=i,y=*it;
			if (x>y) continue;
			for (vector<int>::iterator p=r[i].begin();p!=r[i].end();++p)
				if (*lower_bound(r[y].begin(),r[y].end(),*p)==*p)
				{
					H[pii(x,y)]++;
					H[pii(y,x)]++;
				}
		}
	for (map<pii,int>::iterator it=H.begin();it!=H.end();++it)
	{
		if (it->Y==2)
		{
			d[it->X.X].push_back(it->X.Y);
			d[it->X.Y].push_back(it->X.X);
		}
	}
	vector<int> p;
	p.push_back(1);
	u[1]=1;
	for (int i=1,x=1;i<n;++i)
	{
		int flag=0;
		for (int j=0;j<d[x].size();++j)
			if (!u[d[x][j]])
			{
				flag=1;
				x=d[x][j];
				u[x]=1;
				p.push_back(x);
				break;
			}
		if (!flag)
		{
			puts("-1");
			return;
		}
	}
	for (int i=0;i<n;++i)
		v[p[i]]=i+1;
	check();
	if (!found)
	{
		puts("-1");
		return;
	}
	for (int i=1;i<=n;++i)
		printf("%d ",ans[i]);
}

void work()
{
	if (n<=7)
		work_1();
	else
		work_2();
}

int main()
{
	init();
	work();
	return 0;
}