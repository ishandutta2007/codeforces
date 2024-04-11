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

const int maxn = 1100000;

int n;
ll a[maxn],sum;

int main()
{
//	freopen("tmp.in","r",stdin);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	
	ll sum2=(ll)(1+n)*n/2;
	ll add=(sum-sum2)%n,bas=(sum-sum2)/n;
	for(int i=1;i<=n;i++)
	{
		ll x=bas+i;
		if(i<=add) x++;
		printf("%lld%c",x," \n"[i==n]);
	}
	
	return 0;
}