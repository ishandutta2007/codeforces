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
int a[1000005];
int b[1000005];
int r[1000005];

bool check(int x)
{
	r[0]=b[0]-x;
	for(int i=1;i<n;i++)
	{
		r[i]=b[i]-max(0,a[i]-r[i-1]);
		if(r[i]<0) return false;
	}
	return true;
}

bool checkfinal(int x)
{
	r[0]=b[0]-x;
	for(int i=1;i<n;i++)
	{
		r[i]=b[i]-max(0,a[i]-r[i-1]);
	}
	return (r[n-1]+x>=a[0]);
}

void solve()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",b+i);
	}
	int l=0,r=b[0],mid,res=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if(res==-1)
	{
		puts("NO");
		return;
	}
	if(checkfinal(res)) puts("YES");else puts("NO");
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