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
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 110;

int n,k,x,ans;

int main()
{
	scanf("%d%d%d",&n,&k,&x);
	ans=k*x;
	for(int i=1;i<=n-k;i++)
	{
		int x;scanf("%d",&x);
		ans+=x;
	}
	printf("%d\n",ans);
	
	return 0;
}