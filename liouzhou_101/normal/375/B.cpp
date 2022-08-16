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

const int MaxN=5010;

int n,m;
char s[MaxN][MaxN];
int a[MaxN][MaxN],F[MaxN][MaxN];
int head,tail,Q[MaxN];
int L[MaxN],R[MaxN];
int u[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for (int i=1;i<=m;++i)
		for (int j=1;j<=n;++j)
			a[i][j]=s[j][i]-'0';
	swap(n,m);
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
			if (a[i][j]==0)
				F[i][j]=0;
			else
				F[i][j]=F[i-1][j]+1;
	}
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<=n;++j)
			u[j]=0;
		for (int j=1;j<=m;++j)
			u[F[i][j]]++;
		for (int j=n;j>=0;--j)
		{
			u[j]+=u[j+1];
			ans=max(ans,u[j]*j);
		}
		
	}
	cout<<ans<<endl;
	return 0;
}