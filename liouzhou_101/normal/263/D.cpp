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

const int MaxN=100010;

int n,m,k;
vector<int> v[MaxN];

void init()
{
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

vector<int> p;
int u[MaxN];

void work()
{
	for (int i=1;;)
	{
		p.push_back(i);
		u[i]=1;
		int flag=0;
		for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
			if (!u[*it])
			{
				flag=*it;
				break;
			}
		if (!flag) break;
		i=flag;
	}
	int x=*p.rbegin();
	for (int i=0;i<p.size();++i)
		u[p[i]]=i;
	int way=MaxN;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		way=min(way,u[*it]);
	cout<<p.size()-way<<endl;
	for (int i=way;i<p.size();++i)
		printf("%d ",p[i]);
}

int main()
{
	init();
	work();
	return 0;
}