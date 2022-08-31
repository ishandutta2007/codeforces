#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
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

const int MaxN=1<<17;

int n,q;
vector<int> v[MaxN],s[MaxN],w[MaxN],p(MaxN);
int u[MaxN],r[MaxN];

void DFS(int k,int x,int p)
{
	u[x]=k;
	s[k].push_back(x);
	r[x]=s[k].size();
	w[k].push_back(0);
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=p) DFS(k,*it,x);
}

void init()
{
	cin>>n>>q;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (vector<int>::iterator it=v[1].begin();it!=v[1].end();++it)
	{
		w[*it].push_back(0);
		DFS(*it,*it,1);
	}
}

void add(vector<int> &a,int x,int p)
{
	for (;x<a.size();x+=x&-x)
		a[x]+=p;
}

int get(vector<int> &a,int x)
{
	int p=0;
	for (;x;x-=x&-x)
		p+=a[x];
	return p;
}

void work()
{
	int val=0;
	while (q--)
	{
		int t;
		scanf("%d",&t);
		if (!t)
		{
			int x,k,d;
			scanf("%d%d%d",&x,&k,&d);
			if (x==1)
			{
				val+=k;
				add(p,d+1,-k);
			}
			else if (r[x]>d)
			{
				add(w[u[x]],r[x]-d,k);
				add(w[u[x]],r[x]+d+1,-k);
			}
			else
			{
				val+=k;
				add(p,d-r[x]+1,-k);
				add(w[u[x]],d-r[x]+1,k);
				add(w[u[x]],r[x]+d+1,-k);
			}
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",val+get(p,r[x])+get(w[u[x]],r[x]));
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}