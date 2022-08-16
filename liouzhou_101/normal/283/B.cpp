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

const int MaxN=200010;

int n;
int a[MaxN];
int u[MaxN][2];
ll F[MaxN][2];

ll calc(int x,int p)
{
	if (x<1||x>n) return 0;
	if (u[x][p]==a[1]||u[x][p]==-1) return -1;
	if (u[x][p]) return F[x][p];
	u[x][p]=a[1];
	ll t=p?calc(x-a[x],0):calc(x+a[x],1);
	return (t==-1)?u[x][p]=-1:F[x][p]=t+a[x];
}

int main()
{
	cin>>n;
	for (int i=2;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<n;++i)
	{
		a[1]=i;
		u[1][0]=0;
		printf("%I64d\n",calc(1,0));
	}
	return 0;
}