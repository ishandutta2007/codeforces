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
ll a,b;

bool dfs(ll a,ll b)
{
	if(a>=b) swap(a,b);
	if(a==0) return false;
	bool temp=dfs(a,b%a);
	if(temp==false) return true;
	ll t=(b-(b%a));
	t/=a;
	if((a&2)==1)
	{
		return (t%2==1);
	}
	else
	{
		return (t%(a+1)%2==0);
	}
}

void solve()
{
	if(dfs(a,b)) printf("First\n");else printf("Second\n");
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%I64d%I64d",&a,&b);
		solve();
	}
	return 0;
}