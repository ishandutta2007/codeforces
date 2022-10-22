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
int q;
set <pair<int,pair<int,int> > >squ;
int res;
vector <pair<int,pii> > tbd;

void solve()
{
	int l,r,type;
	scanf("%d%d%d",&l,&r,&type);
	r++;
	tbd.clear();
	set <pair<int,pair<int,int> > > :: iterator endpos=squ.upper_bound(mp(r,mp(inf,inf)));
	set <pair<int,pair<int,int> > > :: iterator stpos=squ.upper_bound(mp(l,mp(inf,inf)));
	for(set <pair<int,pair<int,int> > > :: iterator it=stpos;it!=endpos;it++)
	{
		tbd.push_back(*it);
		if(it->second.first==2) res-=it->second.second;
	}
	pair<int,pii> pre=*(--endpos);
	pair<int,pii> newl=mp(l,mp(type,r-l));
	pair<int,pii> newr=mp(r,mp(pre.second.first,pre.second.second-(r-pre.first)));
	set <pair<int,pii> > :: iterator preit=(--stpos);
	pre=*preit;
	pre.second.second=l-pre.first;
	if(preit->second.first==2) res-=preit->second.second;
	squ.erase(preit);
	if(pre.second.first==2) res+=pre.second.second;
	if(pre.second.second) squ.insert(pre);
	endpos++;
	stpos++;
	for(int i=0;i<tbd.size();i++)
	{
		squ.erase(tbd[i]);
	}
	if(newl.second.second) squ.insert(newl);
	if(newr.second.second) squ.insert(newr);
	if(newl.second.first==2) res+=newl.second.second;
	if(newr.second.first==2) res+=newr.second.second;
	printf("%d\n",res);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>q;
	squ.insert(mp(1,mp(2,n)));
	res=n;
	while(q--)
	{
		solve();
	}
	return 0;
}