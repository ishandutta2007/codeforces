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
int k,n;
int da[300005],db[300005];
int a[300005],b[300005],id[300005];
vector <pair<int,int> >vec;

pair<int,vector<int> >solve()
{
	vec.clear();
	for(int i=0;i<n;i++)
	{
		vec.push_back(mp(a[i],id[i]));
	}
	sort(all(vec));
	reverse(all(vec));
	vector <int> res;
	for(int i=0;i<n;i++)
	{
		res.push_back(vec[i].second);
	}
	return mp(n,res);
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<'-'<<b[i]<<endl;
//	}
//	set <pair<int,int> > :: iterator it=squ.end();
//	it--;
//	int now=it->second;
//	cout<<now<<endl;
//	int ans=0;
//	vector <int> res;
//	while(true)
//	{
//		ans++;
//		res.push_back(now);
//		int x=db[now];
//		if(squ.empty()) break;
//		if(squ.begin()->first>=x) break;
//		it=squ.lower_bound(mp(x,-1));
//		now=it->second;
//		squ.erase(it);
//	}
//	return mp(ans,res);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>k;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",da+i,db+i);
	}
	n=0;
	for(int i=0;i<k;i++)
	{
		if(da[i]<db[i])
		{
			a[n]=da[i];
			b[n]=db[i];
			id[n]=i;
			n++;
		}
	}
	pair<int,vector<int> >a=solve();
//	return 0;
	n=0;
	for(int i=0;i<k;i++)
	{
		if(da[i]>db[i])
		{
			::a[n]=db[i];
			b[n]=da[i];
			id[n]=i;
			n++;
		}
	}
	pair<int,vector<int> >b=solve();
	reverse(all(b.second));
	if(a.first>b.first)
	{
		cout<<a.first<<endl;
		for(int i=0;i<a.first;i++)
		{
			printf("%d ",a.second[i]+1);
		}
	}
	else
	{
		cout<<b.first<<endl;
		for(int i=0;i<b.first;i++)
		{
			printf("%d ",b.second[i]+1);
		}
	}
	cout<<endl;
	return 0;
}