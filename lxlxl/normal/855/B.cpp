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
using namespace std;

const int maxn = 210000;

int n,m;
ll p,q,r;
ll a[maxn];

ll f[maxn];

int main()
{
	scanf("%d%I64d%I64d%I64d",&n,&p,&q,&r);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	
	f[0]=LLONG_MIN;
	for(int i=1;i<=n;i++) f[i]=max(f[i-1],a[i]*p);
	for(int i=1;i<=n;i++) f[i]=max(f[i-1],f[i]+a[i]*q);
	for(int i=1;i<=n;i++) f[i]=max(f[i-1],f[i]+a[i]*r);
	
	printf("%I64d\n",f[n]);
	
    return 0;
}