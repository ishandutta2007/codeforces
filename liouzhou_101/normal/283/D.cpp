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

const int MaxN=5010;

int n;
ll a[MaxN];
int F[MaxN];
bool u[MaxN][MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=n;i>=1;--i)
	{
		ll k=a[i];
		for (int j=i-1;j>=1;--j)
		{
			if (k%2==0)
			{
				k/=2;
				if (a[j]%k==0&&a[j]/k%2==1) u[j][i]=1;
			}
			else
				if (a[j]%k==0) u[j][i]=1;
		}
		u[0][i]=1;
		u[i][n+1]=1;
	}
	for (int i=1;i<=n+1;++i)
	{
		F[i]=MaxN;
		for (int j=0;j<i;++j)
			if (u[j][i]) F[i]=min(F[i],F[j]+i-j-1);
	}
	cout<<F[n+1]<<endl;
	return 0;
}