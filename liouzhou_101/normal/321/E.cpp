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

const int MaxN=4010;
const int MaxK=810;
const int INF=1000000000;

int n,k;
int s[MaxN][MaxN];
int F[MaxK][MaxN];
int v[MaxN];

void solve(int k,int L,int R,int x,int y)
{
	if (L>R) return;
	int m=(L+R)>>1;
	v[m]=x;
	F[k][m]=INF;
	for (int i=x;i<=y&&i<m;++i)
	{
		int t=F[k-1][i]+s[m][m]-2*s[m][i]+s[i][i];
		if (F[k][m]>t)
		{
			F[k][m]=t;
			v[m]=i;
		}
	}
	if (L==R) return;
	solve(k,L,m-1,x,v[m]);
	solve(k,m+1,R,v[m],y);
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			scanf("%d",&s[i][j]);
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	for (int j=1;j<=n;++j)
		F[1][j]=s[j][j];
	for (int i=2;i<=k;++i)
		solve(i,1,n,1,n);
	cout<<F[k][n]/2<<endl;
	return 0;
}