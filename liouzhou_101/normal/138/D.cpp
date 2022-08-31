#include<cstdio>
#include<iostream>
#include<set>

using namespace std;

const int MaxN=42;

int n,m;
char s[MaxN][MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>s[i]+1;
}

int F[MaxN][MaxN][MaxN][MaxN][2],u[MaxN][MaxN][MaxN][MaxN][2];

int solve(int x1,int x2,int y1,int y2,int p)
{
	int &F=::F[x1][x2][y1][y2][p],&u=::u[x1][x2][y1][y2][p];
	if (u) return F;
	u=1;
	set<int> H;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			int x=i+j,y=n-i+1+j;
			if ((x&1)!=p) continue;
			if (!(x1<=x&&x<=x2&&y1<=y&&y<=y2)) continue;
			if (s[i][j]=='L')
				H.insert(solve(x1,x-1,y1,y2,p)^solve(x+1,x2,y1,y2,p));
			else if (s[i][j]=='R')
				H.insert(solve(x1,x2,y1,y-1,p)^solve(x1,x2,y+1,y2,p));
			else
				H.insert(solve(x1,x-1,y1,y-1,p)^solve(x1,x-1,y+1,y2,p)^solve(x+1,x2,y1,y-1,p)^solve(x+1,x2,y+1,y2,p));
		}
	for (;H.count(F);++F);
	return F;
}

void work()
{
	if (solve(2,n+m,2,n+m,0)^solve(2,n+m,2,n+m,1))
		puts("WIN");
	else
		puts("LOSE");
}

int main()
{
	init();
	work();
	return 0;
}