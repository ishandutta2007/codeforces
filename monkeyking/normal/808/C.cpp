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
int n,w;
int v[105];
int a[105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>w;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		int need=ceil(v[i],2);
		if(need>w) over("-1");
		a[i]=need;
		w-=need;
	}
	vector <pair<int,int> > vsort;
	for(int i=0;i<n;i++)
	{
		vsort.push_back(mp(v[i],i));
	}
	sort(all(vsort));
	reverse(all(vsort));
	for(int i=0;i<n;i++)
	{
		int id=vsort[i].second;
		int need=v[id]-a[id];
		if(need<=w)
		{
			a[id]+=need;
			w-=need;
		}
		else
		{
			a[id]+=w;
			w=0;
			break;
		}
	}
	assert(w==0);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}