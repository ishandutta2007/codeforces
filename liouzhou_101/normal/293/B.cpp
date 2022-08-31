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

const int MaxN=14;
const int MOD=1000000007;

int n,m,k;
int a[MaxN][MaxN],s[MaxN][MaxN];
int u[MaxN];
int LOG2[10010];

int DFS(int x,int y)
{
	if (y>m) return DFS(x+1,1);
	if (x>n) return 1;
	int t=s[x-1][y]|s[x][y-1];
	int p=0;
	int w=-1;
	for (int v=(~t)&((1<<k)-1);v;v-=v&-v)
	{
		int i=LOG2[v&-v]+1;
		if (!(t&1<<(i-1))&&(a[x][y]==i||!a[x][y]))
		{
			s[x][y]=t|1<<(i-1);
			if (!u[i]++)
			{
				if (w==-1) w=DFS(x,y+1);
				p+=w;
			}
			else
				p+=DFS(x,y+1);
			p%=MOD;
			--u[i];
		}
	}
	return p;
}

int main()
{
	cin>>n>>m>>k;
	if (n+m-1>k)
	{
		puts("0");
		return 0;
	}
	for (int i=0;i<=k;++i)
		LOG2[1<<i]=i;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			u[a[i][j]]++;
		}
	cout<<DFS(1,1)<<endl;
	return 0;
}