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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1010;

int n,m;
int px[MaxN],py[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		px[x]=1;
		py[y]=1;
	}
	int ans=0;
	for (int i=2;i<=n-1;++i)
	{
		if (!px[i]&&!py[i])
		{
			ans+=2;
			if (n%2==1&&i==n/2+1) --ans;
		}
		else if (!px[i]||!py[i])
			++ans;
	}
	cout<<ans<<endl;
	return 0;
}