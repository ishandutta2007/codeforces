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
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
int l[200005];
int r[200005];
bool zero[200005];

int main()
{
//	freopen("input.txt","r",stdin)
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		zero[i]=(x==0);
	}
	for(int i=0;i<n;i++)
	{
		l[i]=(i?l[i-1]:n);
		if(zero[i]) l[i]=i;
	}
	for(int i=n-1;i>=0;i--)
	{
		r[i]=(i==n-1?-1:r[i+1]);
		if(zero[i]) r[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",min(abs(i-l[i]),abs(i-r[i])));
	}
	return 0;
}