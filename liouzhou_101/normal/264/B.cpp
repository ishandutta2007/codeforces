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

const int MaxN=100010;

int n;
int a[MaxN];
int F[MaxN];
int v[MaxN];

void check(int i,int k)
{
	if (k==1) return;
	F[i]=max(F[i],v[k]+1);
}

void save(int i,int k)
{
	v[k]=max(v[k],F[i]);
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int ans=1;
	for (int i=1;i<=n;++i)
	{
		F[i]=1;
		for (int j=1;j*j<=a[i];++j)
		{
			if (a[i]%j==0)
			{
				check(i,j);
				if (j*j!=a[i]) check(i,a[i]/j);
			}
		}
		for (int j=1;j*j<=a[i];++j)
		{
			if (a[i]%j==0)
			{
				save(i,j);
				if (j*j!=a[i]) save(i,a[i]/j);
			}
		}
		ans=max(ans,F[i]);
	}
	cout<<ans<<endl;
	return 0;
}