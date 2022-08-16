#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

int a[MaxN];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=0;
	for (int T=0;T<k;++T)
	{
		int m;
		scanf("%d",&m);
		ans+=m-1;
		int x;
		scanf("%d",&x);
		for (int i=2;i<=m;++i)
		{
			int y;
			scanf("%d",&y);
			a[x]=y;
			x=y;
		}
	}
	int x=1;
	while (a[x]==x+1) ++x;
	ans-=x-1;
	ans+=n-x;
	cout<<ans<<endl;
	return 0;
}