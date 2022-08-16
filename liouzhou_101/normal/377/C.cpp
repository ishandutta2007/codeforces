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

const int MaxN=110;
const int INF=1000000000;

int n;
int a[MaxN];

int m;
int v[MaxN],w[MaxN];

int F[21][1<<20];
bool u[21][1<<20];

int pos[1<<20];

int DP(int k,int s)
{
	if (k>m) return 0;
	if (u[k][s]) return F[k][s];
	u[k][s]=1;
	if (w[k]==1)
	{
		F[k][s]=-INF;
		if (v[k]==1)
		{
			for (int x=s;x;x-=x&-x)
			{
				int p=pos[x&-x];
				F[k][s]=max(F[k][s],DP(k+1,s^1<<p)+a[p]);
			}
		}
		else
		{
			for (int x=s;x;x-=x&-x)
			{
				int p=pos[x&-x];
				F[k][s]=max(F[k][s],DP(k+1,s^1<<p));
			}
		}
	}
	else
	{
		F[k][s]=INF;
		if (v[k]==1)
		{
			for (int x=s;x;x-=x&-x)
			{
				int p=pos[x&-x];
				F[k][s]=min(F[k][s],DP(k+1,s^1<<p)-a[p]);
			}
		}
		else
		{
			for (int x=s;x;x-=x&-x)
			{
				int p=pos[x&-x];
				F[k][s]=min(F[k][s],DP(k+1,s^1<<p));
			}
		}
	}
	return F[k][s];
}

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	cin>>m;
	for (int i=0;i<m;++i)
		pos[1<<i]=i;
	for (int i=1;i<=m;++i)
	{
		string s;
		cin>>s>>w[i];
		if (s=="p")
			v[i]=1;
		else
			v[i]=2;
	}
	cout<<DP(1,(1<<m)-1)<<endl;
	return 0;
}