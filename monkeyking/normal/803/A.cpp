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
bool a[105][105];
int k;
int n;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	if(k>n*n) over(-1);
	for(int i=0;i<n;i++)
	{
		if(k==0 || k==1) break;
		for(int j=i;j<n;j++)
		{
			if(i==j) a[i][j]=1,k--;
			else a[i][j]=a[j][i]=1,k-=2;
			if(k==1 || k==0) break;
		}
		if(k==1 || k==0) break;
	}
	for(int i=0;i<n;i++)
	{
		if(k==1 && a[i][i]==0)
		{
			a[i][i]=1;
			k--;
			break;
		}
	}
	assert(k==0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}