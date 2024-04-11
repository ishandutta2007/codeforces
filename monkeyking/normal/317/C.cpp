//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,v,m;
//int a[305];
//int b[305];
//vector <int> edges[305];
//int c[305];
//int visit[305];
//int cnt;
//ll s[305];
//vector <pair<pii,int> > res;
//int dist[305];
//
//void dfs(int x)
//{
//    visit[x]=1;
//    c[x]=cnt;
//    for(auto u:edges[x])
//    {
//        if(visit[u]) continue;
//        dfs(u);
//    }
//}
//
//inline void bfs(int src)
//{
//    memset(visit,0,sizeof(visit));
//    visit[src]=1;
//    dist[src]=0;
//    queue <int> que;
//    que.push(src);
//    while(!que.empty())
//    {
//        int x=que.front();
//        que.pop();
//        for(auto u:edges[x])
//        {
//            if(visit[u]) continue;
//            dist[u]=dist[x]+1;
//            visit[u]=1;
//            que.push(u);
//        }
//    }
//}
//
//inline void liu(int x,int y,int flow)
//{
//    // if(flow==0) return;
//    assert(flow>=0);
//    a[x]-=flow;
//    assert(a[x]>=0);
//    a[y]+=flow;
//    assert(a[y]<=v);
//    res.push_back(mp(mp(x,y),flow));
//    // cout<<x+1<<"->"<<1+y<<':'<<flow<<endl;
//}
//
//inline void liu(int i,int flow,vector <int> &routes)
//{
//    if(i==(int)routes.size()-1) return;
//    int nxt=routes[i+1];
//    int now=routes[i];
//    if(a[nxt]+flow<=v)
//    {
//        liu(now,nxt,flow);
//        liu(i+1,flow,routes);
//    }
//    else
//    {
//        int original_a_now=a[now];
//        int moved=v-a[nxt];
//        liu(now,nxt,v-a[nxt]);
//        liu(i+1,flow,routes);
//        liu(now,nxt,flow-moved);
//        int new_a_now=a[now];
//    }
//}
//
//inline void adjust(int x,int y)
//{
//    assert(a[x]!=b[x]);
//    assert(a[y]!=b[y]);
//    // cout<<"adjsuting: "<<x+1<<' '<<y+1<<endl;
//    if(a[x]<b[x]) swap(x,y);
//    int flow=min(abs(a[x]-b[x]),abs(a[y]-b[y]));
//    bfs(x);
//    vector <int> routes;
//    routes.push_back(y);
//    while(y!=x)
//    {
//        int step=dist[y];
//        int nxt=-1;
//        for(auto ny:edges[y])
//        {
//            if(dist[ny]!=step-1) continue;
//            nxt=ny;
//            break;
//        }
//        y=nxt;
//        routes.push_back(y);
//    }
//    reverse(all(routes));
//    int notEq=0;
//    for(auto x:routes)
//    {
//        // cout<<x+1<<' '<<a[x]<<' '<<b[x]<<endl;
//        if(a[x]!=b[x]) notEq++;
//    }
//    vector <pair<pii,int> > ans;
//    liu(0,flow,routes);
//    for(auto x:routes)
//    {
//        // cout<<x+1<<' '<<a[x]<<' '<<b[x]<<endl;
//        if(a[x]!=b[x]) notEq--;
//    }
//    assert(notEq>=1);
//}
//
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    cin>>n>>v>>m;
//    for(int i=0;i<n;i++)
//    {
//        cin>>a[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        cin>>b[i];
//    }
//    for(int i=0;i<m;i++)
//    {
//        int x,y;
//        scanf("%d%d",&x,&y);
//        x--;
//        y--;
//        edges[x].push_back(y);
//        edges[y].push_back(x);
//    }
//    for(int i=0;i<n;i++)
//    {
//        if(visit[i]) continue;
//        dfs(i);
//        cnt++;
//    }
//    for(int i=0;i<n;i++)
//    {
//        s[c[i]]+=a[i];
//        s[c[i]]-=b[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        if(s[i]) over("NO");
//    }
//    int prev;
//    int cur;
//    for(int i=0;i<n;i++)
//    {
//        if(a[i]==b[i]) continue;
//        for(int j=i+1;j<n;j++)
//        {
//            if(c[i]!=c[j]) continue;
//            if(a[j]==b[j]) continue;
//            if(a[i]<b[i] && a[j]<b[j]) continue;
//            if(a[i]>b[i] && a[j]>b[j]) continue;
//            // prev=res.size();
//            // assert(a[i]!=b[i]);
//            // assert(a[j]!=b[j]);
//            adjust(i,j);
//            break;
//            // cur=res.size();
//            // assert(cur-prev<=2*n);
//            // assert((a[i]==b[i]) || (a[j]==b[j]));
//            // cout<<a[i]<<' '<<b[i]<<' '<<a[j]<<' '<<b[j]<<endl;
//        }
//        if(a[i]!=b[i]) i--;
//    }
//    cout<<res.size()<<endl;
//    for(auto &e:res)
//    {
//        printf("%d %d %d\n",e.first.first+1,e.first.second+1,e.second);
//        // cout<<e.first.first+1<<' '<<e.first.second+1<<' '<<e.second<<endl;
//    }
//    return 0;
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
#ifdef __TAKE_CONTROL_OF_MOD
int mod;
#else
const int mod=1e9+7;
#endif
const int gmod=2;
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
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T> 
void operator *= (vector <T> &vec,int k)
{
	for(auto &x:vec) x*=k;
}

template <typename T>
void operator -= (vector <T> &a,const vector <T> &b)
{
	assert(a.size()==b.size());
	for(size_t it=0;it<a.size();it++)
	{
		a[it]-=b[it];
	}
}

template <typename T>
vector <T> operator * (const vector <T> &vec,int k)
{
	vector <T> res(vec);
	res*=k;
	return res;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
using namespace std;
int n,v,m;
int a[305];
int b[305];
vector <int> edges[305];
int c[305];
int visit[305];
int cnt;
ll s[305];
vector <pair<pii,int> > res;
int dist[305];

void dfs(int x)
{
    visit[x]=1;
    c[x]=cnt;
    for(auto u:edges[x])
    {
        if(visit[u]) continue;
        dfs(u);
    }
}

inline void bfs(int src)
{
    memset(visit,0,sizeof(visit));
    visit[src]=1;
    dist[src]=0;
    queue <int> que;
    que.push(src);
    while(!que.empty())
    {
        int x=que.front();
        que.pop();
        for(auto u:edges[x])
        {
            if(visit[u]) continue;
            dist[u]=dist[x]+1;
            visit[u]=1;
            que.push(u);
        }
    }
}

inline void liu(int x,int y,int flow)
{
    // if(flow==0) return;
    assert(flow>=0);
    a[x]-=flow;
    assert(a[x]>=0);
    a[y]+=flow;
    assert(a[y]<=v);
    res.push_back(mp(mp(x,y),flow));
    // cout<<x+1<<"->"<<1+y<<':'<<flow<<endl;
}

inline void liu(int i,int flow,vector <int> &routes)
{
    if(i==(int)routes.size()-1) return;
    int nxt=routes[i+1];
    int now=routes[i];
    if(a[nxt]+flow<=v)
    {
        liu(now,nxt,flow);
        liu(i+1,flow,routes);
    }
    else
    {
        int original_a_now=a[now];
        int moved=v-a[nxt];
        liu(now,nxt,v-a[nxt]);
        liu(i+1,flow,routes);
        liu(now,nxt,flow-moved);
        int new_a_now=a[now];
    }
}

inline void adjust(int x,int y)
{
    assert(a[x]!=b[x]);
    assert(a[y]!=b[y]);
    // cout<<"adjsuting: "<<x+1<<' '<<y+1<<endl;
    if(a[x]<b[x]) swap(x,y);
    int flow=min(abs(a[x]-b[x]),abs(a[y]-b[y]));
    bfs(x);
    vector <int> routes;
    routes.push_back(y);
    while(y!=x)
    {
        int step=dist[y];
        int nxt=-1;
        for(auto ny:edges[y])
        {
            if(dist[ny]!=step-1) continue;
            nxt=ny;
            break;
        }
        y=nxt;
        routes.push_back(y);
    }
    reverse(all(routes));
    int notEq=0;
    for(auto x:routes)
    {
        // cout<<x+1<<' '<<a[x]<<' '<<b[x]<<endl;
        if(a[x]!=b[x]) notEq++;
    }
    vector <pair<pii,int> > ans;
    liu(0,flow,routes);
    for(auto x:routes)
    {
        // cout<<x+1<<' '<<a[x]<<' '<<b[x]<<endl;
        if(a[x]!=b[x]) notEq--;
    }
    assert(notEq>=1);
}

int main()
{
    // freopen("input.txt","r",stdin);
    cin>>n>>v>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        if(visit[i]) continue;
        dfs(i);
        cnt++;
    }
    for(int i=0;i<n;i++)
    {
        s[c[i]]+=a[i];
        s[c[i]]-=b[i];
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]) over("NO");
    }
    int prev;
    int cur;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) continue;
        for(int j=i+1;j<n;j++)
        {
            if(c[i]!=c[j]) continue;
            if(a[j]==b[j]) continue;
            if(a[i]<b[i] && a[j]<b[j]) continue;
            if(a[i]>b[i] && a[j]>b[j]) continue;
            // prev=res.size();
            // assert(a[i]!=b[i]);
            // assert(a[j]!=b[j]);
            adjust(i,j);
            break;
            // cur=res.size();
            // assert(cur-prev<=2*n);
            // assert((a[i]==b[i]) || (a[j]==b[j]));
            // cout<<a[i]<<' '<<b[i]<<' '<<a[j]<<' '<<b[j]<<endl;
        }
        if(a[i]!=b[i]) i--;
    }
    cout<<res.size()<<endl;
    for(auto &e:res)
    {
        printf("%d %d %d\n",e.first.first+1,e.first.second+1,e.second);
        // cout<<e.first.first+1<<' '<<e.first.second+1<<' '<<e.second<<endl;
    }
    return 0;
}