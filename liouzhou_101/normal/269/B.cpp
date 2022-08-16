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

const int MaxN=5010;

int n,m;
int s[MaxN];
ld x[MaxN];
int F[MaxN][MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>s[i]>>x[i];
	for (int i=1;i<=n;++i)
	{
		int p=0;
		for (int j=0;j<=m;++j)
		{
			p=max(p,F[i-1][j]);
			F[i][j]=max(F[i-1][j],p+(s[i]==j));
		}
	}
	int ans=0;
	for (int i=1;i<=m;++i)
		ans=max(ans,F[n][i]);
	cout<<n-ans<<endl;
	return 0;
}