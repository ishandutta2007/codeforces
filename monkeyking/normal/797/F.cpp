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
ll dp[5005][5005];
pair<ll,int> que[5005];
int l,r;
int n,m;
int hole[5005];
int cap[5005];
int mice[5005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",mice+i);
	}
	sort(mice,mice+n);
	vector <pii> vSort(m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",hole+i,cap+i);
		vSort[i]=mp(hole[i],cap[i]);
	}
	sort(all(vSort));
	for(int i=0;i<m;i++)
	{
		hole[i]=vSort[i].first;
		cap[i]=vSort[i].second;
	}
	memset(dp,0x3f,sizeof(dp));
	ll llinf=dp[0][0];
	dp[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		dp[i][0]=0;
		l=r=0;
		que[r++]=mp(0,0);
		ll sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=abs(hole[i-1]-mice[j-1]);
			ll newValue=dp[i-1][j]-sum;
			while(l!=r && que[r-1].first>=newValue) r--;
			que[r++]=mp(newValue,j);
			while(l!=r && j-que[l].second>cap[i-1]) l++;
			assert(l!=r);
			dp[i][j]=que[l].first+sum;
		}
	}
	cout<<(dp[m][n]==llinf?-1:dp[m][n])<<endl;
	return 0;
}