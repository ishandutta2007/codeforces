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
int a[100005];
int l[100005];
int r[100005];
int lRange[100005];
int rRange[100005];
int par[100005];
int n;
int root;

void findRoot()
{
	for(int i=0;i<n;i++)
	{
		if(par[i]==-1)
		{
			root=i;
			break;
		}
	}
}

void dfs(int x,int ql,int qr)
{
	lRange[x]=ql;
	rRange[x]=qr;
	if(l[x]!=-1) dfs(l[x],ql,min(qr,a[x]-1));
	if(r[x]!=-1) dfs(r[x],max(ql,a[x]+1),qr);
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(par,-1,sizeof(par));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",a+i,l+i,r+i);
		if(l[i]!=-1) l[i]--;
		if(r[i]!=-1) r[i]--;
		par[l[i]]=i;
		par[r[i]]=i;
	}
	findRoot();
	dfs(root,0,1000000000);
	map <int,bool> reachable;
	for(int i=0;i<n;i++)
	{
		if(lRange[i]<=a[i] && a[i]<=rRange[i]) reachable[a[i]]=true;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(reachable.count(a[i])) res++;
	}
	cout<<n-res<<endl;
	return 0;
}