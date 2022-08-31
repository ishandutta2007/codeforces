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

int m,n;
int q=MaxN;
int a[MaxN],u[MaxN];

int main()
{
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		q=min(q,x);
	}
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=n;i>=1;i-=q+2)
	{
		for (int j=1;j<=q;++j)
			if (i-j+1>0) u[i-j+1]=1;
	}
	int ans=0;
	for (int i=1;i<=n;++i)
		if (u[i]) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}