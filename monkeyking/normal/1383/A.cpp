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
char a[100005];
char b[100005];
int n;

void solve()
{
	scanf("%d%s%s",&n,a,b);
	for(int i=0;i<n;i++)
	{
		if(a[i]>b[i])
		{
			cout<<-1<<endl;
			return;
		}
	}
	int res=0;
	while(true)
	{
		bool equal=true;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i]) equal=false;
		}
		if(equal) break;
		char c='z';
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i]) continue;
			chmin(c,b[i]);
		}
		vector <char> v;
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i]) continue;
			if(b[i]==c) v.push_back(a[i]);
		}
		sort(all(v));
		v.erase(unique(all(v)),v.end());
		res+=(int)v.size();
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i]) continue;
			for(auto &ch:v)
			{
				if(a[i]==ch) a[i]=c;
			}
		}
	}
	cout<<res<<endl;
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