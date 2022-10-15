#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n,m;
	cin>>n>>m;
	long double sx,sy;
	printf("? %d\n",n*2+2);
	for(int i=0; i<n; ++i)
		printf("%d %d\n",i,0),
		printf("%d.999999999999999 %d\n",i,m);
	printf("%d %d\n",n,m);
	printf("0 %d\n",m);
	fflush(stdout);
	cin>>sx;
	printf("? %d\n",m*2+2);
	for(int i=0; i<m; ++i)
		printf("%d %d\n",0,i),
		printf("%d %d.999999999999999\n",n,i);
	printf("%d %d\n",n,m);
	printf("%d 0\n",n);
	fflush(stdout);
	cin>>sy;
	printf("! %.9Lf %.9Lf\n",sy*n-0.5,sx*m-0.5);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}