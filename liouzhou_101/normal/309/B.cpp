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
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1000010;

int n,r,c;
char t[MaxN*5];
string s[MaxN];
int v[MaxN];
int to[MaxN][20];

int main()
{
	cin>>n>>r>>c;
	for (int i=1;i<=n;++i)
	{
		scanf("%s",t);
		s[i]=t;
		v[i]=s[i].size();
	}
	for (int i=1;i<=n;++i)
		v[i]+=v[i-1];
	for (int i=n,j=n;i>=1;--i)
	{
		while (v[j]-v[i-1]+j-i>c) --j;
		to[i][0]=j+1;
	}
	to[n+1][0]=n+1;
	for (int k=1;k<20;++k)
		for (int i=1;i<=n+1;++i)
			to[i][k]=to[to[i][k-1]][k-1];
	pii p(0,0);
	for (int i=1;i<=n;++i)
	{
		int x=i;
		int t=r;
		for (int k=19;k>=0;--k)
			if (t>=1<<k)
			{
				t-=1<<k;
				x=to[x][k];
			}
		p=max(p,pii(x-i,i));
	}
	int x=p.Y;
	for (int i=1;i<=r;++i)
	{
		for (int j=x;j<to[x][0];++j)
		{
			if (j>x) putchar(' ');
			printf("%s",s[j].c_str());
		}
		puts("");
		x=to[x][0];
	}
	return 0;
}