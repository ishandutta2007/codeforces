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
const int N=2e6;
const int sp[]={9,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
int sd[N+100];
ll sum[N+100];
int ans[155][15];

void solve0(int n)
{
	vector <int> vec;
	while(true)
	{
		if(n>9)
		{
			vec.push_back(9);
			n-=9;
		}
		else
		{
			vec.push_back(n);
			break;
		}
	}
	sort(all(vec));
	for(auto &x:vec)
	{
		cout<<x;
	}
	cout<<endl;
}

int get0(int n)
{
	vector <int> vec;
	while(true)
	{
		if(n>9)
		{
			vec.push_back(9);
			n-=9;
		}
		else
		{
			vec.push_back(n);
			break;
		}
	}
	sort(all(vec));
	int res=0;
	for(auto &x:vec)
	{
		res=res*10+x;
	}
	return res;
}

void solve1even(int n)
{
	if(n<=100)
	{
		cout<<ans[n][1]<<endl;
		return;
	}
	n=n/2+4;
	vector <int> vec;
	int i=0;
	while(true)
	{
		if(n>9)
		{
			vec.push_back(sp[i]);
			n-=sp[i++];
		}
		else
		{
			vec.push_back(n);
			break;
		}
	}
	reverse(all(vec));
	for(auto &x:vec)
	{
		cout<<x;
	}
	cout<<endl;
}

void solve1(int n)
{
	if(!(n&1))
	{
		solve1even(n);
		return;
	}
	n=n/2+1;
	cout<<get0(n)-1<<endl;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	if(k==0) solve0(n);
	else if(k==1) solve1(n);
	else cout<<ans[n][k]<<endl;
}

void init()
{
	memset(ans,-1,sizeof(ans));
	for(int x=1;x<=N+20;x++)
	{
		sd[x]=sd[x/10]+x%10;
	}
	sum[0]=sd[0];
	for(int x=1;x<=N+20;x++)
	{
		sum[x]=sum[x-1]+sd[x];
	}
	ll n;
	for(int x=0;x<=N;x++)
	{
		for(int k=0;k<=9;k++)
		{
			n=sum[x+k]-(x?sum[x-1]:0);
			if(n>150) break;
			if(ans[n][k]==-1) ans[n][k]=x;
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	init();
//	for(int i=0;i<=150;i+=2)
//	{
//		cout<<i<<' '<<ans[i][1]<<endl;
//	}
	while(T--)
	{
		solve();
	}
	return 0;
}