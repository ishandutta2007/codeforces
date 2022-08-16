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

const int MaxN=42;

int n,m,q;
int s[MaxN][MaxN];
int F[MaxN][MaxN][MaxN][MaxN];
int u[MaxN][MaxN][MaxN][MaxN];
int G[MaxN][MaxN][MaxN][MaxN];
int v[MaxN];

int sum(int a,int b,int c,int d)
{
	return s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
}

int dp(int a,int b,int c,int d)
{
	if (a>c||b>d) return 0;
	int &u=::u[a][b][c][d];
	int &F=::F[a][b][c][d];
	if (u) return F;
	u=1;
	if (a==c) return F=G[a][c][b][d];
	return F=dp(a,b,c-1,d)+dp(a+1,b,c,d)-dp(a+1,b,c-1,d)+G[a][c][b][d];
}

int main()
{
	cin>>n>>m>>q;
	for (int i=1;i<=n;++i)
	{
		char s[MaxN];
		cin>>s+1;
		for (int j=1;j<=m;++j)
			::s[i][j]=s[j]=='1';
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for (int a=1;a<=n;++a)
		for (int b=a;b<=n;++b)
		{
			for (int c=1;c<=m;++c)
				v[c]=sum(a,c,b,c);
			for (int c=1;c<=m;++c)
			{
				int now=0,cnt=0;
				for (int d=c;d<=m;++d)
				{
					if (v[d]==0)
					{
						now++;
						cnt+=now;
					}
					else
						now=0;
					G[a][b][c][d]=cnt;
				}
			}
		}
	while (q--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",dp(a,b,c,d));
	}
	return 0;
}