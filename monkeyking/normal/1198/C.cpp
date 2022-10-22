#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int T;
int d[300005];
vector <pii> vec[300005];
int n,m;
vector <int> edge;
bool visit[300005];
bool use[300005];
vector <pii> order;

void dfs(int x)
{
	visit[x]=true;
	for(auto u:vec[x])
	{
		if(!use[x] && !use[u.first]) edge.push_back(u.second),use[x]=true,use[u.first]=true;
		if(visit[u.first]) continue;
		dfs(u.first);
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<3*n;i++)
	{
		d[i]=0;
		vec[i].clear();
		visit[i]=false;
		use[i]=false;
	}
	int x,y;
	order.clear();
	edge.clear();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		d[x]++;
		d[y]++;
		vec[x].push_back(mp(y,i+1));
		vec[y].push_back(mp(x,i+1));
	}
	for(int i=0;i<3*n;i++)
	{
		order.push_back(mp(d[i],i));
	}
	for(int i=0;i<3*n;i++)
	{
		if(visit[i]) continue;
		dfs(i);
	}
	if(edge.size()>=n)
	{
		printf("Matching\n");
		for(int i=0;i<n;i++)
		{
			printf("%d ",edge[i]);
		}
		puts("");
		return;
	}
	for(int i=0;i<3*n;i++)
	{
		use[i]=false;
	}
	sort(all(order));
	int cnt=0;
	printf("IndSet\n");
	for(auto i:order)
	{
		if(cnt==n)
		{
			puts("");
			return;
		}
		if(use[i.second]) continue;
		if(i.first==0)
		{
			printf("%d ",i.second+1);
			cnt++;
			use[i.second]=true;
			continue;
		}
		use[i.second]=true;
		printf("%d ",i.second+1);
		cnt++;
		for(auto u:vec[i.second])
		{
			use[u.first]=true;
		}
	}
	puts("");
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}