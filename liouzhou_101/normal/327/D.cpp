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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=510;

int n,m;
char s[MaxN][MaxN];
vector<pair<int,pii> > p;
int u[MaxN][MaxN];

void DFS(int x,int y,int f=1)
{
	if (u[x][y]) return;
	if (s[x][y]!='.') return;
	u[x][y]=1;
	p.push_back(pair<int,pii>('B',pii(x,y)));
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x,y-1);
	DFS(x,y+1);
	if (f)
	{
		p.push_back(pair<int,pii>('D',pii(x,y)));
		p.push_back(pair<int,pii>('R',pii(x,y)));
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			DFS(i,j,0);
	cout<<p.size()<<endl;
	for (int i=0;i<p.size();++i)
	{
		putchar(p[i].X);
		printf(" %d",p[i].Y.X);
		printf(" %d\n",p[i].Y.Y);
	}
	return 0;
}