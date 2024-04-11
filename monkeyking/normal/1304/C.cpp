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
int n,m;
ll t[105],l[105],h[105];

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>l[i]>>h[i];
	}
	ll rl=m,rr=m;
	for(int i=1;i<=n;i++)
	{
		ll gap=t[i]-t[i-1];
		rl=min(rl,rl-gap);
		rr=max(rr,rr+gap);
		rl=max(rl,l[i]);
		rr=min(rr,h[i]);
		if(rl>rr)
		{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}