#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=510;

int n,m,k;
char s[MaxN][MaxN];
int u[MaxN][MaxN];
int cnt,cut[MaxN][MaxN];

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

void DFS(int x,int y)
{
	if (cnt==k) return;
	u[x][y]=1;
	for (int i=0;i<4;++i)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if (s[tx][ty]=='.') if (!u[tx][ty]) DFS(tx,ty);
		if (cnt==k) return;
	}
	cut[x][y]=1;
	++cnt;
}

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (s[i][j]=='.')
			{
				DFS(i,j);
				for (int i=1;i<=n;++i)
				{
					for (int j=1;j<=m;++j)
						if (cut[i][j]) s[i][j]='X';
					puts(s[i]+1);
				}
				return 0;
			}
	return 0;
}