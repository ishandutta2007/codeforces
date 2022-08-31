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

const int MaxN=2010;

int n,m,k,tot;
char s[MaxN][MaxN],ts[MaxN][MaxN];
int a[MaxN][MaxN],ta[MaxN][MaxN];

void answer_yes()
{
	puts("YES");
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
			printf("%d ",a[i][j]);
		puts("");
	}
}

void solve_0()
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			a[i][j]=1;
	int t=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<m;++j)
		{
			if (s[2*i-1][j]=='E'&&a[i][j]==a[i][j+1]) ++t;
			if (s[2*i-1][j]=='N'&&a[i][j]!=a[i][j+1]) ++t;
		}
	for (int i=1;i<n;++i)
		for (int j=1;j<=m;++j)
		{
			if (s[i*2][j]=='E'&&a[i][j]==a[i+1][j]) ++t;
			if (s[i*2][j]=='N'&&a[i][j]!=a[i+1][j]) ++t;
		}
	if (t*4>=tot*3)
		answer_yes();
	else
		puts("NO");
}

void solve()
{
	int flag=0;
	if (n>m)
	{
		flag=1;
		for (int i=1;i<=2*n-1;++i)
			for (int j=1;j<=m-i%2;++j)
				ts[i][j]=s[i][j];
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m-1;++j)
				s[j*2][i]=ts[i*2-1][j];
		for (int i=1;i<n;++i)
			for (int j=1;j<=m;++j)
				s[j*2-1][i]=ts[i*2][j];
		swap(n,m);
	}
	for (int i=1;i<=n;++i)
	{
		a[i][1]=1;
		for (int j=1;j<m;++j)
			if (s[i*2-1][j]=='E')
				a[i][j+1]=a[i][j];
			else
				a[i][j+1]=3-a[i][j];
	}
	for (int i=1;i<n;++i)
	{
		int t=0;
		for (int j=1;j<=m;++j)
		{
			if (s[i*2][j]=='E'&&a[i][j]==a[i+1][j]) ++t;
			if (s[i*2][j]=='N'&&a[i][j]!=a[i+1][j]) ++t;
		}
		if (t*2<m)
			for (int j=1;j<=m;++j)
				a[i+1][j]=3-a[i+1][j];
	}
	if (flag)
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				ta[i][j]=a[i][j];
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				a[j][i]=ta[i][j];
		swap(n,m);
	}
	answer_yes();
}

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=2*n-1;++i)
	{
		scanf("%s",s[i]+1);
		tot+=strlen(s[i]+1);
	}
	if (k==1)
		solve_0();
	else
		solve();
	return 0;
}