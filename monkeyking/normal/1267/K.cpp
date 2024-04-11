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
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
ll n;
int a[25];
int s[25];
ll fac[25];

void solve()
{
	cin>>n;
	int len=0;
	ll fac=1;
	
	while(n)
	{
		a[len++]=n%(len+1);
		fac*=len;
		n/=(len+1);
	}
	
	memset(s,0,sizeof(s));
	
	for(int i=0;i<len;i++)
	{
		s[a[i]]++;
	}
	
	ll res=1;
	ll miss=1;
	ll nowmiss=s[0]-1;
	ll now=s[0];
	
	for(int i=1;i<=len;i++)
	{
		now+=s[i];
		nowmiss+=s[i];
		if(i!=len) miss*=nowmiss;
		res*=now;
		nowmiss--;
		now--;
	}
	
	for(int i=0;i<=len;i++)
	{
		res/=::fac[s[i]];
	}
	
	if(s[0]!=0) miss/=::fac[s[0]-1];
	for(int i=1;i<=len-1;i++)
	{
		miss/=::fac[s[i]];
	}
	
	cout<<res-(s[0]==0?0:miss)-1<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	fac[0]=1;
	for(int i=1;i<=20;i++)
	{
		fac[i]=fac[i-1]*i;
	}
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}