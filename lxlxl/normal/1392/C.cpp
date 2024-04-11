#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#include<cassert>
#define ll long long
#define db double
#define fir first
#define sec second
#define mp make_pair
using namespace std;

const int maxn = 210000;

int n;
int a[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		ll ans=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		for(int i=1;i<n;i++) ans+=max(0,a[i]-a[i+1]);
		printf("%lld\n",ans);
	}
	
	return 0;
}