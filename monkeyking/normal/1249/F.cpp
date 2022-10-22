//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,k;
//int a[1000005];
//vector <int> edges[1000005];
//int depth[1000005];
//int par[1000005];
//
//namespace FastIO
//{
//    const int INPUT_SIZE=10*1000000*3;
//    char buf[INPUT_SIZE+5];
//    int cursor=0;
//    inline void init()
//    {
//        fread(buf,1,INPUT_SIZE,stdin);
//    }
//    inline char getchar()
//    {
//        return buf[cursor++];
//    }
//    inline int getnum()
//    {
//        static int res;
//        static char c;
//        res=0;
//        c=0;
//        while(!isdigit(c)) c=getchar();
//        while(isdigit(c))
//        {
//            res=(res<<3)+(res<<1)+c-'0';
//            c=getchar();
//        }
//        return res;
//    }
//}
//using FastIO::getnum;
//
//struct DpValue
//{
//    vector <ll> v;
//};
//
//ll tmp[1000005];
//inline void merge(DpValue *a,DpValue *b)
//{
//    vector <ll> &va=a->v;
//    const vector <ll> &vb=b->v;
//    int len=vb.size();
//    int n=va.size();
//
//    for(int i=len-1;i>=0;i--)
//    {
//        tmp[n-i-1]=0;
//        chmax(tmp[n-i-1],va[n-i-1]);
//        chmax(tmp[n-i-1],vb[len-i-1]);
//        int oth=max(i,k-i+1);
//        assert(n-i-1>=0);
//        if(oth<(int)vb.size()) chmax(tmp[n-i-1],va[n-i-1]+vb[len-oth-1]);
//        if(oth<(int)va.size()) chmax(tmp[n-i-1],va[n-oth-1]+vb[len-i-1]);
//    }
//    for(int i=0;i<len-1;i++)
//    {
//        chmax(tmp[n-i-1],tmp[n-(i+1)-1]);
//    }
//    for(int i=len-1;i>=0;i--)
//    {
//    	assert(n-i-1>=0);
//        va[n-i-1]=tmp[n-i-1];
//    }
//    delete b;
//}
//
//DpValue* dfs(int x)
//{
//    DpValue *res=nullptr;
//    if(edges[x].empty())
//    {
//        res=new DpValue;
//        res->v.push_back(a[x]);
//        res->v.push_back(a[x]);
//        return res;
//    }
//    int maxDid=-1;
//    for(auto u:edges[x])
//    {
//        if(maxDid==-1 || depth[u]>depth[maxDid]) maxDid=u;
//    }
//    for(auto u:edges[x])
//    {
//        if(u==maxDid) res=dfs(u);
//    }
//    for(auto u:edges[x])
//    {
//        if(u==maxDid) continue;
//        merge(res,dfs(u));
//    }
//    ll tmp=0;
//    if((int)res->v.size()>k+1) tmp=res->v[(int)res->v.size()-1-(k+1)];
//    // res->v.push_back(tmp+(ll)a[x]);
//    chmax(res->v.back(),tmp+a[x]);
//    res->v.push_back(res->v.back());
//    return res;
//}
//
//void go(int x,int p)
//{
//    par[x]=p;
//    for(auto u:edges[x])
//    {
//        if(u==p) continue;
//        go(u,x);
//        chmax(depth[x],depth[u]);
//    }
//    depth[x]++;
//}
//
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    // freopen("c.in","r",stdin);
//    // freopen("c.out","w",stdout);
//    FastIO::init();
//    n=getnum();
//    k=getnum();
//    // cout<<n<<' '<<k<<endl;
//    for(int i=0;i<n;i++)
//    {
//        a[i]=getnum();
//    }
//    int x,y;
//    for(int i=0;i<n-1;i++)
//    {
//        x=getnum();
//        y=getnum();
//        x--;
//        y--;
//        // cout<<x<<' '<<y<<endl;
//        edges[x].push_back(y);
//        edges[y].push_back(x);
//    }
//    // return 0;   
//    go(0,-1);
//    for(int i=0;i<n;i++)
//    {
//        for(size_t j=0;j<edges[i].size();j++)
//        {
//            if(edges[i][j]==par[i])
//            {
//                for(size_t k=j;k<edges[i].size()-1;k++)
//                {
//                    edges[i][k]=edges[i][k+1];
//                }
//                edges[i].pop_back();
//                break;
//            }
//        }
//    }
//    DpValue *res=dfs(0);
//    // cout<<res->v<<endl;
//    // cout<<res->v[(int)res->v.size()-1-2]<<endl;
//    ll ans=0;
//    for(size_t i=0;i<res->v.size();i++)
//    {
//        chmax(ans,res->v[i]);
//    }
//    cout<<ans<<endl;
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

template <typename T1,typename T2,typename T3>
ostream & operator << (ostream &cout,map <T1,T2,T3> m)
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
int n,k;
int a[1000005];
vector <int> edges[1000005];
int depth[1000005];
int par[1000005];

namespace FastIO
{
    const int INPUT_SIZE=10*1000000*3;
    char buf[INPUT_SIZE+5];
    int cursor=0;
    inline void init()
    {
        fread(buf,1,INPUT_SIZE,stdin);
    }
    inline char getchar()
    {
        return buf[cursor++];
    }
    inline int getnum()
    {
        static int res;
        static char c;
        res=0;
        c=0;
        while(!isdigit(c)) c=getchar();
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res;
    }
}
using FastIO::getnum;

struct DpValue
{
    vector <ll> v;
};

ll tmp[1000005];
inline void merge(DpValue *a,DpValue *b)
{
    vector <ll> &va=a->v;
    const vector <ll> &vb=b->v;
    int len=vb.size();
    int n=va.size();

    for(int i=len-1;i>=0;i--)
    {
        tmp[n-i-1]=0;
        chmax(tmp[n-i-1],va[n-i-1]);
        chmax(tmp[n-i-1],vb[len-i-1]);
        int oth=max(i,k-i+1);
        assert(n-i-1>=0);
        if(oth<(int)vb.size()) chmax(tmp[n-i-1],va[n-i-1]+vb[len-oth-1]);
        if(oth<(int)va.size()) chmax(tmp[n-i-1],va[n-oth-1]+vb[len-i-1]);
    }
    for(int i=0;i<len-1;i++)
    {
        chmax(tmp[n-i-1],tmp[n-(i+1)-1]);
    }
    for(int i=len-1;i>=0;i--)
    {
    	assert(n-i-1>=0);
        va[n-i-1]=tmp[n-i-1];
    }
    delete b;
}

DpValue* dfs(int x)
{
    DpValue *res=nullptr;
    if(edges[x].empty())
    {
        res=new DpValue;
        res->v.push_back(a[x]);
        res->v.push_back(a[x]);
        return res;
    }
    int maxDid=-1;
    for(auto u:edges[x])
    {
        if(maxDid==-1 || depth[u]>depth[maxDid]) maxDid=u;
    }
    for(auto u:edges[x])
    {
        if(u==maxDid) res=dfs(u);
    }
    for(auto u:edges[x])
    {
        if(u==maxDid) continue;
        merge(res,dfs(u));
    }
    ll tmp=0;
    if((int)res->v.size()>k+1) tmp=res->v[(int)res->v.size()-1-(k+1)];
    // res->v.push_back(tmp+(ll)a[x]);
    chmax(res->v.back(),tmp+a[x]);
    res->v.push_back(res->v.back());
    return res;
}

void go(int x,int p)
{
    par[x]=p;
    for(auto u:edges[x])
    {
        if(u==p) continue;
        go(u,x);
        chmax(depth[x],depth[u]);
    }
    depth[x]++;
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("c.in","r",stdin);
    // freopen("c.out","w",stdout);
    FastIO::init();
    n=getnum();
    k=getnum();
    // cout<<n<<' '<<k<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=getnum();
    }
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        x=getnum();
        y=getnum();
        x--;
        y--;
        // cout<<x<<' '<<y<<endl;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    // return 0;   
    go(0,-1);
    for(int i=0;i<n;i++)
    {
        for(size_t j=0;j<edges[i].size();j++)
        {
            if(edges[i][j]==par[i])
            {
                for(size_t k=j;k<edges[i].size()-1;k++)
                {
                    edges[i][k]=edges[i][k+1];
                }
                edges[i].pop_back();
                break;
            }
        }
    }
    DpValue *res=dfs(0);
    // cout<<res->v<<endl;
    // cout<<res->v[(int)res->v.size()-1-2]<<endl;
    ll ans=0;
    for(size_t i=0;i<res->v.size();i++)
    {
        chmax(ans,res->v[i]);
    }
    cout<<ans<<endl;
    return 0;
}