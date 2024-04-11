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
const int mod=924844033;
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
using namespace std;
int n,m;
int G,S;

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

struct Edge
{
    int from;
    int to;
    ll cost1;
    ll cost2;
    int id;
    inline void input()
    {
        from=getnum();
        to=getnum();
        from--;
        to--;
        cost1=getnum();
        cost2=getnum();
        cost1*=G;
        cost2*=S;
    }
    bool operator < (const Edge &d)const&
    {
        return cost1<d.cost1;
    }
}data[50005],data2[50005];
bool disabled[500005];

struct Tree
{
    vector <pair<int,ll> > edges[205];
    pair<pii,ll> data[205];
    bool isTree()
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=(int)edges[i].size();
        }
        assert(res%2==0);
        res/=2;
        return (res==n-1);
    }
    bool dfs(int x,int par,int goal,vector <pair<pii,ll> > &v)
    {
        if(x==goal) return true;
        bool flag=false;
        for(auto &e:edges[x])
        {
            if(e.first==par) continue;
            if(dfs(e.first,x,goal,v)) flag=true,v.push_back(mp(mp(x,e.first),e.second));
        }
        return flag;
    }
    inline void insert(int x,int y,ll weight)
    {
        vector <pair<pii,ll> > v;
        int flag=dfs(x,-1,y,v);
        if(flag==0)
        {
            edges[x].push_back(mp(y,weight));
            edges[y].push_back(mp(x,weight));
        }
        else
        {
            sort(all(v),[](const pair<pii,ll> &a,const pair<pii,ll> &b)
            {
                return a.second>b.second;
            });
            assert((int)v.size()>=1);
            if(v[0].second<weight) return;
            erase(v[0].first.first,v[0].first.second,v[0].second);
            edges[x].push_back(mp(y,weight));
            edges[y].push_back(mp(x,weight));
        }
    }
    inline void erase(int x,int y,ll weight)
    {
        int m=0;
        for(int i=0;i<n;i++)
        {
            for(auto &e:edges[i])
            {
                if(e.first<i) continue;
                data[m++]=mp(mp(i,e.first),e.second);
            }
        }
        if(x>y) swap(x,y);
        for(int i=0;i<m;i++)
        {
            if(data[i].first.first==x && data[i].first.second==y && data[i].second==weight)
            {
                for(int j=i;j<m-1;j++)
                {
                    data[j]=data[j+1];
                }
                m--;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            edges[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            edges[data[i].first.first].push_back(mp(data[i].first.second,data[i].second));
            edges[data[i].first.second].push_back(mp(data[i].first.first,data[i].second));
        }
    }
}tree;

inline bool isTree()
{
    return tree.isTree();
}

inline void insert(const Edge &e)
{
    tree.insert(e.from,e.to,e.cost2);
}

inline void erase(const Edge &e)
{
    tree.erase(e.from,e.to,e.cost2);
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("c.in","r",stdin);
    // freopen("c.out","w",stdout);
    cin>>n>>m>>G>>S;
    int nm=0;
    for(int i=0;i<m;i++)
    {
        data[nm].input();
        data[nm].id=nm;
        data2[nm]=data[nm];
        if(data[nm].to!=data[nm].from) nm++;
    }
    m=nm;
    // for(int i=0;i<m;i++)
    // {
    //     cout<<"data2[i]="<<data2[i].cost2<<endl;
    // }
    sort(data,data+m);
    sort(data2,data2+m,[](const Edge &a,const Edge &b)
    {
        return a.cost2>b.cost2;
    });
    int i=0;
    ll res=llinf*2;
    while(!isTree())
    {
        if(i>=m) break;
        insert(data[i]);
        i++;
    }
    // cout<<data[i-1].cost1<<' '<<data2[0].cost2<<endl;
    if(isTree()) chmin(res,data2[0].cost2+data[i-1].cost1);
    for(int j=0;j<m;j++)
    {
        erase(data2[j]);
        disabled[data2[j].id]=true;
        while(!isTree())
        {
            if(i>=m) break;
            if(disabled[data[i].id])
            {
                i++;
                continue;
            }
            insert(data[i]);
            i++;
        }
        // cout<<data[i-1].cost1<<' '<<(j==m-1?0:data2[j+1].cost2)<<endl;
        if(isTree()) chmin(res,(j==m-1?0:data2[j+1].cost2)+data[i-1].cost1);
    }
    if(res>=llinf*2)
    {
        puts("-1");
    }
    else
    {
        cout<<res<<endl;
    }
    return 0;
}