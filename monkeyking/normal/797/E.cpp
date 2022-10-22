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
const int B=300;
using namespace std;
int n;
int a[100005];
int steps[100005][B+5];

void solve()
{
	int p,k;
	scanf("%d%d",&p,&k);
	p--;
	int res=0;
	if(k<=B) res=steps[p][k];
	else
	{
		while(p<n)
		{
			p=p+a[p]+k;
			res++;
		}
	}
	printf("%d\n",res);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=B;j++)
		{
			int nexti=i+j+a[i];
			steps[i][j]=1+(nexti>=n?0:steps[nexti][j]);
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}