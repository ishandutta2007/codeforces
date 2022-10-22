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
int a[105];
int b[105];
int n,k1,k2;

void solve()
{
	cin>>n>>k1>>k2;
	for(int i=0;i<k1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<k2;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<k1;i++)
	{
		if(a[i]==n)
		{
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}