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
pii p[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d%d",&p[i].X,&p[i].Y);
	sort(p+1,p+n+1);
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		int now=p[i].X;
		if (p[i].Y==1)
			++now;
		else
		while (p[i].Y>1)
		{
			now++;
			p[i].Y=(p[i].Y-1)/4+1;
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}