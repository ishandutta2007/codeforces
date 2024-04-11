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
int dp[1005][1005];
pair<int,pair<int,int> > trace[1005][1005];
int n;
int a[1005];
vector <pair<int,int> >ans;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<a[0]<<endl;
		cout<<1<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<max(a[0],a[1])<<endl;
		cout<<1<<' '<<2<<endl;
		return 0;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=max(a[1],a[2]);
	dp[1][1]=max(a[0],a[2]);
	dp[1][2]=max(a[0],a[1]);
	trace[1][0]={-1,{1,2}};
	trace[1][1]={-1,{0,2}};
	trace[1][2]={-1,{0,1}};
	for(int i=1;i<(n-1)/2;i++)
	{
		for(int j=0;j<=i*2;j++)
		{
			if(dp[i+1][j]>dp[i][j]+max(a[i*2+1],a[i*2+2]))
			{
				dp[i+1][j]=dp[i][j]+max(a[i*2+1],a[i*2+2]);
				trace[i+1][j]=mp(j,mp(i*2+1,i*2+2));
			}
			if(dp[i+1][i*2+1]>dp[i][j]+max(a[j],a[i*2+2]))
			{
				dp[i+1][i*2+1]=dp[i][j]+max(a[j],a[i*2+2]);
				trace[i+1][i*2+1]=mp(j,mp(j,i*2+2));
			}
			if(dp[i+1][i*2+2]>dp[i][j]+max(a[j],a[i*2+1]))
			{
				dp[i+1][i*2+2]=dp[i][j]+max(a[j],a[i*2+1]);
				trace[i+1][i*2+2]=mp(j,mp(j,i*2+1));
			}
		}
	}
	int t=(n-1)/2;
	int res=inf,k=-1;
	if(n&1)
	{
		for(int i=0;i<n;i++)
		{
			if(res>dp[t][i]+a[i])
			{
				res=dp[t][i]+a[i];
				k=i;
			}
		}
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if(res>dp[t][i]+max(a[i],a[n-1]))
			{
//				cout<<trace[t][i].second.first<<' '<<trace[t][i].second.second<<endl;
				res=dp[t][i]+max(a[i],a[n-1]);
				k=i;
			}
		}
	}
	int tk=k;
	cout<<res<<endl;
//	cout<<trace[1][2].second.first<<' '<<trace[1][2].second.second<<endl;
	for(int i=t;i>=1;i--)
	{
		ans.push_back(trace[i][k].second);
		k=trace[i][k].first;
	}
	reverse(all(ans));
	for(int i=0;i<t;i++)
	{
		cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
	}
	if(n&1)
	{
		cout<<tk+1<<endl;
	}
	else
	{
		cout<<tk+1<<' '<<n<<endl;
	}
	return 0;
}