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
int n;
int a[200005];
int h[200005];
int bit[400005];
int numh,numa;
vector <int> mh;
vector <int> ma;
//map <int,int> mh;
//map <int,int> ma;
int nn;
vector <int> vec[200005];
bool appear[200005];

void add(int x)
{
	while(x<=nn)
	{
		bit[x]++;
		x+=x & -x;
	}
}

int query(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x&=x-1;
	}
	return res;
}

int sum(int l,int r)
{
	l++;
	r--;
	if(l>r) return 0;
	return query(r)-(l?query(l-1):0);
}

ll calc(int x)
{
	return 1LL*x*(x+1)/2;
}

int main()
{
	cin>>n;
	nn=1;
	while(nn<n)
	{
		nn<<=1;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",a+i,h+i);
	}
	for(int i=0;i<n;i++)
	{
		ma.push_back(a[i]);
		mh.push_back(h[i]);
//		if(mh.find(h[i])==mh.end()) mh[h[i]]=++numh;
//		if(ma.find(a[i])==ma.end()) ma[a[i]]=++numa;
	}
	sort(all(ma));
	sort(all(mh));
	ma.erase(unique(all(ma)),ma.end());
	mh.erase(unique(all(mh)),mh.end());
	numa=ma.size();
	numh=mh.size();
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(all(ma),a[i])-ma.begin()+1;
//		a[i]=ma[a[i]];
	}
	for(int i=0;i<n;i++)
	{
		vec[lower_bound(all(mh),h[i])-mh.begin()+1].push_back(a[i]);
	}
	for(int i=1;i<=numh;i++)
	{
		sort(all(vec[i]));
	}
	ll res=0;
	int size=0;
	for(int height=numh;height>=1;height--)
	{
//		cout<<vec[height].front()<<endl;
//		cout<<sum(0,vec[height].front())<<endl;
		res-=calc(sum(0,vec[height].front()));
		for(int i=0;i<(int)vec[height].size()-1;i++)
		{
			res-=calc(sum(vec[height][i],vec[height][i+1]));
		}
		res-=calc(sum(vec[height].back(),numa+1));
		for(auto x:vec[height])
		{
//			cout<<x<<' ';
			if(appear[x]) continue;
			size++;
			appear[x]=true;
			add(x);
		}
//		cout<<endl;
		res+=calc(size);
	}
	cout<<res<<endl;
	return 0;
}