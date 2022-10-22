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
#define int ll
const int inf=2039074182;
using namespace std;
vector <pair<int,int> > duration[200005];
vector <int> mincost[200005];
int n,x;
int l[200005],r[200005],cost[200005];
pair<int,pair<int,int> > num[200005];

int bs(int right,int time)
{
	if(duration[time].size()==0) return inf;
	int l=0,r=duration[time].size()-1,mid,res=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(duration[time][mid].first>right)
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if(res==-1) return inf;
	return mincost[time][res];
}
#undef int

int main()
{
	#define int ll
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i]>>cost[i];
		num[i].first=l[i];
		num[i].second.first=r[i];
		num[i].second.second=cost[i];
	}
	sort(num,num+n);
	for(int i=0;i<n;i++)
	{
		duration[r[i]-l[i]+1].push_back(mp(l[i],cost[i]));
	}
	for(int i=1;i<=200000;i++)
	{
//		cout<<i<<endl;
		sort(all(duration[i]));
		if(duration[i].size()==0) continue;
		mincost[i].resize(duration[i].size());
		mincost[i][duration[i].size()-1]=duration[i][duration[i].size()-1].second;
		for(int j=(ll)duration[i].size()-2;j>=0;j--)
		{
//			cout<<j<<endl;
			mincost[i][j]=min(mincost[i][j+1],duration[i][j].second);
		}
	}
//	for(int i=1;i<=5;i++)
//	{
//		cout<<i<<':';
//		for(int j=0;j<mincost[i].size();j++)
//		{
//			cout<<mincost[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	int res=inf;
	for(int i=0;i<n;i++)
	{
		int l=num[i].first;
		int r=num[i].second.first;
		int cost=num[i].second.second;
		if(r-l+1>=x) continue;
		int time=x-(r-l+1);
		res=min(res,cost+bs(r,time));
	}
	if(res==inf)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<res<<endl;
	}
	return 0;
}