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
const ll llinf=1LL*inf*inf;
using namespace std;
int n;
int nn;
int p[200005];
int l[200005];
int r[200005];
vector <int> vec[200005];
int sum[524288+5];
bool tag[524288+5];

void dfs(int x,int p)
{
	static int Time=0;
	l[x]=Time++;
	for(auto u:vec[x])
	{
		if(u==p) continue;
		dfs(u,x);
	}
	r[x]=Time;
}

inline void pushdown(int x,int l,int r)
{
	if(x>=nn) return;
	tag[x*2]^=tag[x];
	tag[x*2+1]^=tag[x];
	int sz=r-l>>1;
	if(tag[x])
	{
		sum[x*2]=sz-sum[x*2];
		sum[x*2+1]=sz-sum[x*2+1];
	}
	tag[x]=0;
}

void reverse(int x,int l,int r,int ql,int qr)
{
	if(l>=ql && r<=qr)
	{
		sum[x]=r-l-sum[x];
		tag[x]^=1;
		return;
	}
	if(r<=ql || l>=qr) return;
	pushdown(x,l,r);
	reverse(x*2,l,l+r>>1,ql,qr);
	reverse(x*2+1,l+r>>1,r,ql,qr);
	sum[x]=sum[x*2]+sum[x*2+1];
}

int query(int x,int l,int r,int ql,int qr)
{
	if(l>=ql && r<=qr) return sum[x];
	if(r<=ql || l>=qr) return 0;
	pushdown(x,l,r);
	return query(x*2,l,l+r>>1,ql,qr)+query(x*2+1,l+r>>1,r,ql,qr);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n;
	nn=1;
	while(nn<n)
	{
		nn<<=1;
	}
	for(int i=1;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
		vec[p[i]].push_back(i);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x) reverse(1,0,nn,l[i],l[i]+1);
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		int x;
		cin>>s>>x;
		x--;
		if(s=="get")
		{
			cout<<query(1,0,nn,l[x],r[x])<<endl;
		}
		else
		{
			reverse(1,0,nn,l[x],r[x]);
		}
	}
	return 0;
}