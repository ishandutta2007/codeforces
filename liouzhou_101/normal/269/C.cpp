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

int n,m;

struct edge
{
	int x,y,c;
}p[MaxN];

struct node
{
	int x,y,c,p,b;
};

vector<node> v[MaxN];
int ans[MaxN];
queue<int> Q;
int s[MaxN],sum[MaxN],used[MaxN],u[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		v[x].push_back((node){x,y,c,i,0});
		v[y].push_back((node){y,x,c,i,1});
		s[x]+=c;
		s[y]+=c;
	}
	Q.push(1);
	used[1]=1;
	while (!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for (vector<node>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (!u[it->p])
			{
				u[it->p]=1;
				ans[it->p]=it->b;
				sum[it->y]+=it->c;
				if (sum[it->y]*2==s[it->y]&&!used[it->y])
				{
					used[it->y]=1;
					if (it->y!=n) Q.push(it->y);
				}
			}
	}
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}