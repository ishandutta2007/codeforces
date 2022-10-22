//Original Code:
//#include <self/utility>
//#include <self/FastIO>
//using namespace std;
//int n,m;
//vector <pii> edges[100005];
//int dist[100005];
//int st[100005];
//int best[100005];
//int trace[100005];
//int trace0[100005];
//int visit[100005];
//int dist0[100005];
//
//void bfs()
//{
//	queue <int> que;
//	memset(dist,-1,sizeof(dist));
//	que.push(0);
//	dist[0]=0;
//	while(que.size())
//	{
//		int x=que.front();
//		que.pop();
//		for(auto &e:edges[x])
//		{
//			int u=e.first;
//			if(dist[u]!=-1) continue;
//			dist[u]=dist[x]+1;
//			que.push(u);
//		}
//	}
//}
//
//void bfs2()
//{
//	memset(dist0,-1,sizeof(dist0));
//	st[n-1]=1;
//	dist0[n-1]=0;
//	queue <int> que;
//	que.push(n-1);
//	while(que.size())
//	{
//		int x=que.front();
//		que.pop();
//		for(auto &e:edges[x])
//		{
//			if(st[e.first]) continue;
//			if(e.second!=0) continue;
//			st[e.first]=true;
//			que.push(e.first);
//			trace0[e.first]=x;
//			dist0[e.first]=dist0[x]+1;
//		}
//	}
//}
//
//void bfs3(vector <int> now,int len)
//{
//	sort(now.begin(),now.end(),[](const int &a,const int &b)
//	{
//		return dist0[a]<dist0[b];
//	});
//	memset(best,0x3f,sizeof(best));
//	vector <int> nxt;
//	for(auto x:now)
//	{
//		visit[x]=true;
//	}
//	for(int i=0;i<len;i++)
//	{
//		nxt.clear();
//		for(auto x:now)
//		{
//			for(auto &e:edges[x])
//			{
//				if(dist[e.first]!=dist[x]-1) continue;
//				chmin(best[i],e.second);
//			}
//		}
//		for(auto x:now)
//		{
//			for(auto &e:edges[x])
//			{
//				if(e.second==best[i] && !visit[e.first])
//				{
//					if(dist[e.first]!=dist[x]-1) continue;
//					visit[e.first]=true;
//					trace[e.first]=x;
//					nxt.push_back(e.first);
//				}
//			}
//		}
//		now=nxt;
//	}
//	if(len==0)
//	{
//		puts("0");
//	}
//	for(int i=0;i<len;i++)
//	{
//		putchar('0'+best[i]);
//	}
//	puts("");
//	vector <int> cities;
//	int x=0;
//	while(dist[x]!=len)
//	{
//		cities.push_back(x);
//		x=trace[x];
//	}
//	while(x!=n-1)
//	{
//		cities.push_back(x);
//		x=trace0[x];
//	}
//	printf("%d\n",(int)cities.size()+1);
//	for(auto x:cities)
//	{
//		printf("%d ",x);
//	}
//	printf("%d\n",n-1);
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	FastIO::init();
//	n=getnum();
//	m=getnum();
//	for(int i=0;i<m;i++)
//	{
//		int x,y,z;
//		x=getnum();
//		y=getnum();
//		z=getnum();
//		edges[x].push_back(mp(y,z));
//		edges[y].push_back(mp(x,z));
//	}
//	bfs();
//	bfs2();
//	vector <int> v;
//	int minLen=n;
//	for(int i=0;i<n;i++)
//	{
//		if(!st[i]) continue;
//		if(dist[i]==-1) continue;
//		chmin(minLen,dist[i]);
//	}
//	for(int i=0;i<n;i++)
//	{
//		if(!st[i]) continue;
//		if(minLen==dist[i]) v.push_back(i);
//	}
//	bfs3(v,minLen);
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
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
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=5;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
namespace FastIO
{
    const int MaxBufSize=2500000;
    char buf[MaxBufSize];
    int cursor=-1;
    inline void init()
    {
        fread(buf,1,MaxBufSize,stdin);
        cursor=0;
    }
    inline char getchar()
    {
        return (cursor==MaxBufSize?EOF:buf[cursor++]);
    }
    inline ll getnum()
    {
        static ll res;
        static char c;
        static int mut;
        res=0;
        c=0;
        mut=1;
        while(!isdigit(c) && c!='-') c=getchar();
        if(c=='-')
        {
            mut=-1;
            c=getchar();
        }
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res*mut;
    }
} // namespace FastIO
using FastIO::getnum;
using namespace std;
int n,m;
vector <pii> edges[100005];
int dist[100005];
int st[100005];
int best[100005];
int trace[100005];
int trace0[100005];
int visit[100005];
int dist0[100005];

void bfs()
{
	queue <int> que;
	memset(dist,-1,sizeof(dist));
	que.push(0);
	dist[0]=0;
	while(que.size())
	{
		int x=que.front();
		que.pop();
		for(auto &e:edges[x])
		{
			int u=e.first;
			if(dist[u]!=-1) continue;
			dist[u]=dist[x]+1;
			que.push(u);
		}
	}
}

void bfs2()
{
	memset(dist0,-1,sizeof(dist0));
	st[n-1]=1;
	dist0[n-1]=0;
	queue <int> que;
	que.push(n-1);
	while(que.size())
	{
		int x=que.front();
		que.pop();
		for(auto &e:edges[x])
		{
			if(st[e.first]) continue;
			if(e.second!=0) continue;
			st[e.first]=true;
			que.push(e.first);
			trace0[e.first]=x;
			dist0[e.first]=dist0[x]+1;
		}
	}
}

void bfs3(vector <int> now,int len)
{
	sort(now.begin(),now.end(),[](const int &a,const int &b)
	{
		return dist0[a]<dist0[b];
	});
	memset(best,0x3f,sizeof(best));
	vector <int> nxt;
	for(auto x:now)
	{
		visit[x]=true;
	}
	for(int i=0;i<len;i++)
	{
		nxt.clear();
		for(auto x:now)
		{
			for(auto &e:edges[x])
			{
				if(dist[e.first]!=dist[x]-1) continue;
				chmin(best[i],e.second);
			}
		}
		for(auto x:now)
		{
			for(auto &e:edges[x])
			{
				if(e.second==best[i] && !visit[e.first])
				{
					if(dist[e.first]!=dist[x]-1) continue;
					visit[e.first]=true;
					trace[e.first]=x;
					nxt.push_back(e.first);
				}
			}
		}
		now=nxt;
	}
	if(len==0)
	{
		puts("0");
	}
	for(int i=0;i<len;i++)
	{
		putchar('0'+best[i]);
	}
	puts("");
	vector <int> cities;
	int x=0;
	while(dist[x]!=len)
	{
		cities.push_back(x);
		x=trace[x];
	}
	while(x!=n-1)
	{
		cities.push_back(x);
		x=trace0[x];
	}
	printf("%d\n",(int)cities.size()+1);
	for(auto x:cities)
	{
		printf("%d ",x);
	}
	printf("%d\n",n-1);
}

int main()
{
//	// freopen("input.txt","r",stdin);
	FastIO::init();
	n=getnum();
	m=getnum();
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		x=getnum();
		y=getnum();
		z=getnum();
		edges[x].push_back(mp(y,z));
		edges[y].push_back(mp(x,z));
	}
	bfs();
	bfs2();
	vector <int> v;
	int minLen=n;
	for(int i=0;i<n;i++)
	{
		if(!st[i]) continue;
		if(dist[i]==-1) continue;
		chmin(minLen,dist[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(!st[i]) continue;
		if(minLen==dist[i]) v.push_back(i);
	}
	bfs3(v,minLen);
	return 0;
}