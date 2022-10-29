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

const ll maxn = 110000;

ll n,m,q;
ll a[maxn],b[maxn];
ll now,s[maxn][2],sum[maxn];

ll solve()
{
	ll re=LLONG_MAX;
	ll l=0,r=m-n;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(sum[mid]<=now) l=mid+1;
		else r=mid-1;
	}l--; if(l<0) l++;
	re=min(re,abs(now-sum[l]));
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(sum[mid]>=now) r=mid-1;
		else l=mid+1;
	}r++; if(r>m-n) r--;
	re=min(re,abs(now-sum[r]));
	return re;
}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	for(ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(ll i=1;i<=m;i++) scanf("%I64d",&b[i]);
	
	for(ll i=1;i<=n;i++)
	{
		if(i&1) now+=a[i];
		else now-=a[i];
	}
	for(ll i=1;i<=m;i++)
	{
		s[i][0]=s[i-1][0];
		s[i][1]=s[i-1][1];
		if(i&1) s[i][0]-=b[i],s[i][1]+=b[i];
		else s[i][0]+=b[i],s[i][1]-=b[i];
	}
	for(ll i=0;i<=m-n;i++)
	{
		ll l=i,r=i+n;
		if(i&1) sum[i]=s[r][1]-s[l][1];
		else sum[i]=s[r][0]-s[l][0];
		sum[i]=-sum[i];
	}
	sort(sum,sum+m-n+1);
	printf("%I64d\n",solve());
	
	while(q--)
	{
		ll l,r,x; scanf("%I64d%I64d%I64d",&l,&r,&x);
		if((r-l+1)&1)
		{
			if(l&1) now+=(ll)x;
			else now-=(ll)x;
		}
		printf("%I64d\n",solve());
	}
	
	return 0;
}