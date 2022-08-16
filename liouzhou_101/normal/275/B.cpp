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

const int MaxN=60;

int n,m;
char s[MaxN][MaxN];
int u[MaxN][MaxN];

void check(int x,int y,int dx,int dy)
{
	for (int i=x,j=y;s[i][j]=='B';i+=dx,j+=dy)
		u[i][j]=1;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>s[i]+1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			if (s[i][j]!='B') continue;
			memset(u,0,sizeof(u));
			u[i][j]=1;
			for (int x=i,y=j;s[x][y]=='B';--x)
			{
				check(x,y,0,-1);
				check(x,y,0,1);
			}
			for (int x=i,y=j;s[x][y]=='B';++x)
			{
				check(x,y,0,-1);
				check(x,y,0,1);
			}
			for (int x=i,y=j;s[x][y]=='B';--y)
			{
				check(x,y,-1,0);
				check(x,y,1,0);
			}
			for (int x=i,y=j;s[x][y]=='B';++y)
			{
				check(x,y,-1,0);
				check(x,y,1,0);
			}
			for (int x=1;x<=n;++x)
				for (int y=1;y<=m;++y)
					if (s[x][y]=='B'&&!u[x][y])
					{
						puts("NO");
						return 0;
					}
		}
	puts("YES");
	return 0;
}