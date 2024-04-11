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
int a[400005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	if(!(n&1))
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<=2*n;i+=2)
	{
		a[i]=i;
	}
	int k=2;
	for(int i=n+1;i<=2*n;i+=2)
	{
		a[i]=k;
		k+=2;
	}
	for(int i=2;i<=n;i+=2)
	{
		a[i]=k;
		k+=2;
	}
	cout<<"YES\n";
	for(int i=1;i<=2*n;i++)
	{
		printf("%d ",a[i]);
	}
	cout<<endl;
	return 0;
}