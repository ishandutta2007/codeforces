#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int n;
int a[200005];
int b[200005];
ll sum[200005];

ll solve(int a[],int n,int inv)
{
	memcpy(b,a,sizeof(int)*n);
	for(int i=0;i<n;i+=2)
	{
		b[i]=(a[i]-a[i+1])*inv;
	}
	for(int i=0;i<n/2;i++)
	{
		b[i]=b[i*2];
	}
	n/=2;
	if(n==0) return 0;
	sum[0]=b[0];
	ll mn=0;
	chmin(mn,b[0]);
	ll res=0;
	chmax(res,b[0]-mn);
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+b[i];
		chmin(mn,sum[i]);
		chmax(res,sum[i]-mn);
	}
	return res;
}

void solve()
{
	scanf("%d",&n);
	ll base=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		if(!(i&1)) base+=a[i];
	}
	ll res=0;
	chmax(res,solve(a+1,n-1,1));
	chmax(res,solve(a,n,-1));
	printf("%I64d\n",res+base);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}