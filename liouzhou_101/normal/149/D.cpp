#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int MOD=1000000007;

const int MaxN=710;

int n;
char s[MaxN];
int p[MaxN];

void init()
{
	cin>>s+1;
	n=strlen(s+1);
	vector<int> Q;
	Q.clear();
	for (int i=1;i<=n;++i)
	{
		if (s[i]=='(')
			Q.push_back(i);
		else
		{
			p[p[i]=*Q.rbegin()]=i;
			Q.pop_back();
		}
	}
}

long long F[MaxN][MaxN][3][3];

void solve(int x,int y)
{
	if (x+1==y)
	{
		for (int i=1;i<=2;++i)
			F[x][y][i][0]=F[x][y][0][i]=1;
		return;
	}
	if (p[x]==y)
	{
		solve(x+1,y-1);
		for (int k=1;k<=2;++k)
			for (int i=0;i<=2;++i)
				for (int j=0;j<=2;++j)
				{
					if (k!=i) (F[x][y][k][0]+=F[x+1][y-1][i][j])%=MOD;
					if (k!=j) (F[x][y][0][k]+=F[x+1][y-1][i][j])%=MOD;
				}
	}
	else
	{
		solve(x,p[x]);
		solve(p[x]+1,y);
		for (int k=1;k<=2;++k)
			for (int i=0;i<=2;++i)
				for (int j=0;j<=2;++j)
				{
					(F[x][y][k][j]+=F[x][p[x]][k][0]*F[p[x]+1][y][i][j])%=MOD;
					if (k!=i) (F[x][y][0][j]+=F[x][p[x]][0][k]*F[p[x]+1][y][i][j])%=MOD;
				}
	}
}

int main()
{
	init();
	solve(1,n);
	long long ans=0;
	for (int i=0;i<=2;++i)
		for (int j=0;j<=2;++j)
			(ans+=F[1][n][i][j])%=MOD;
	cout<<ans<<endl;
	return 0;
}