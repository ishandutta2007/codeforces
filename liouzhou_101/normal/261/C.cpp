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

const int MaxN=70;

ll n,t;
ll F[MaxN][MaxN];
ll v[MaxN];
ll delta;

void calc(ll n,int k,int p)
{
	if (!n) return;
	if ((1LL<<(k-1))<=n)
	{
		for (int i=0;i<=60;++i)
			if (i+p<=60) v[i+p]+=F[k-1][i];
		calc(n-(1LL<<(k-1)),k-1,p+1);
	}
	else
		calc(n,k-1,p);
}

void solve(ll n,int k)
{
	for (int i=1;i<=60;++i)
		if ((1LL<<i)<=n)
		{
			for (int j=0;j<=60;++j)
				v[j]+=F[i][j];
			n-=1LL<<i;
		}
		else
		{
			calc(n,i,0);
			break;
		}
	cout<<v[k]<<endl;
}

int main()
{
	F[0][0]=1;
	F[1][0]=F[1][1]=1;
	for (int i=2;i<=60;++i)
		for (int j=0;j<=60;++j)
		{
			F[i][j]+=F[i-1][j];
			F[i][j+1]+=F[i-1][j];
		}
	cin>>n>>t;
	for (int k=0;k<=60;++k)
		if ((1LL<<k)==t)
		{
			solve(n,k);
			return 0;
		}
	puts("0");
	return 0;
}