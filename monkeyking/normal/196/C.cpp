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
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
int n;
vector <int> vec[1505];
int son[1505];

struct Point
{
	int x;
	int y;
	int id;
	inline void input()
	{
		cin>>x>>y;
	}
	inline Point operator - (Point p)
	{
		return {x-p.x,y-p.y};
	}
	inline void operator -= (Point p)
	{
		x-=p.x;
		y-=p.y;
	}
	inline ll operator ^ (Point p)
	{
//		cout<<x<<' '<<p.y<<' '<<y<<' '<<p.x<<' '<<1LL*x*p.y-1LL*y*p.x<<endl;
		return 1LL*x*p.y-1LL*y*p.x;
	}
}O;
Point d[1505];
int used[1505];

bool compare(Point x,Point y)
{
	x-=O;
	y-=O;
	assert((x^y)!=0);
	return (x^y)>0;
}

int go(int x,int par=-1)
{
	son[x]=1;
	for(auto u:vec[x])
	{
		if(u==par) continue;
		son[x]+=go(u,x);
	}
	return son[x];
}

void dfs(int x,int par,vector <Point> vp,Point O)
{
//	cout<<x<<' '<<vp.size()<<' '<<son[x]<<endl;
	::O=O;
	sort(all(vp),compare);
	int id=0;
	for(auto u:vec[x])
	{
		if(u==par) continue;
		vector <Point> p;
		used[vp[id].id-1]=u+1;
		for(int i=id+1;i<id+son[u];i++)
		{
			p.push_back(vp[i]);
		}
		dfs(u,x,p,vp[id]);
		id+=son[u];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		d[i].input();
		d[i].id=i+1;
	}
	go(0);
	::O={-inf,-inf/2-1};
	vector <Point> p;
	for(int i=0;i<n;i++)
	{
		if(!used[i]) p.push_back(d[i]);
	}
	sort(all(p),compare);
	used[p[0].id-1]=1;
	vector <Point> tmp;
	for(int i=1;i<n;i++)
	{
		tmp.push_back(p[i]);
	}
	dfs(0,-1,tmp,p[0]);
	for(int i=0;i<n;i++)
	{
		cout<<used[i]<<' ';
	}
	cout<<endl;
	return 0;
}