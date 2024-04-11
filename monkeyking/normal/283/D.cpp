#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cmath>
#define ll long long 
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=1039714778;
template<typename T> inline void chmin(T &x,const T &b) {x=(x<b?x:b);}
template<typename T> inline void chmax(T &x,const T &b) {x=(x>b?x:b);}
int n;
ll a[5005];
int dp[5005];

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("sequence.in","r",stdin);
	// freopen("sequence.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	reverse(a,a+n);
	memset(dp,0x3f,sizeof(dp));
	int res=inf;
	for(int i=0;i<n;i++)
	{
		chmin(dp[i],i);
		for(int j=i+1;j<n;j++)
		{
			ll t=a[i],rm=j-i-1;
			while(t%2==0 && rm>0) t/=2,rm--;
			if(((t&1) && a[j]%t==0) || ((t%2==0) && a[j]%t==t/2))
			{
				chmin(dp[j],dp[i]+(j-i-1));
			}
		}
		chmin(res,dp[i]+n-i-1);
	}
	cout<<res<<endl;
	return 0;
}