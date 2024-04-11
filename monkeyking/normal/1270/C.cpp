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
//#include <self/debug>
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
int n;
int a[100005];

void solve()
{
	cin>>n;
	ll sum=0;
	ll xorsum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		xorsum^=a[i];
	}
	cout<<2<<endl;
	cout<<xorsum<<' '<<xorsum+sum<<endl;
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