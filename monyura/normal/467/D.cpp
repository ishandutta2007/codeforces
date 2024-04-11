#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

struct vert
{
    vector<int> inc;
    vector<int> rev;
    int pred;
    pii val;
    bool was = 0;
} g[200100];

void fillV(int k, char *str)
{
    g[k].val.second= strlen(str);
    g[k].val.first = 0;
    rep(i,0,strlen(str))
    g[k].val.first += str[i] == 'r';
    //    cout<<strlen(str)<<' '<<str<<' '<<g[k].val.first<<' '<<g[k].val.second<<endl;
}

vector<int> vec;
void dfs0(int k)
{
    g[k].was = 1;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (!g[to].was)
            dfs0(to);
    }
    vec.push_back(k);
}


pii Res[200200];
void dfs(int k, int pred)
{
    g[k].was = 1;
    g[k].pred = pred;
    Res[g[k].pred] = min(Res[g[k].pred], g[k].val);
    rep(i,0,g[k].rev.size())
    {
        int to = g[k].rev[i];
        if (!g[to].was)
            dfs(to, pred);
    }
}

vector<int> to[200200];
bool was[200200]={0};
void dfs2(int k)
{
    was[k] = 1;
    rep(i,0,to[k].size())
    {
        int v = to[k][i];
        if (!was[v])
            dfs2(v);
        Res[k] = min(Res[k], Res[v]);
    }
}

void run()
{
    int n;
    cin>>n;
    map<string, int> mp;
    char str[500100];
    int A[100100];
    rep(i,0,n)
    {
        scanf("%s", str);
        int l = strlen(str);
        rep(j,0,l)
        str[j] = tolower(str[j]);
        if (mp.find(str) == mp.end())
        {
            int sz = mp.size();
            mp[str] = sz;
            fillV(sz, str);
        }
        A[i] = mp[str];
    }
    int m;
    cin>>m;
    rep(i,0,m)
    {
        int id[2];
        rep(t,0,2)
        {
            scanf("%s",str);
            rep(j,0,strlen(str))
            str[j] = tolower(str[j]);
            if (mp.find(str) == mp.end())
            {
                int sz = mp.size();
                mp[str] = sz;
                fillV(sz, str);
            }
            id[t] = mp[str];
        }
        g[id[0]].inc.push_back(id[1]);
        g[id[1]].rev.push_back(id[0]);
    }
    rep(i,0,mp.size())
    {
        if (!g[i].was)
            dfs0(i);
    }
    reverse(all(vec));
    rep(i,0,mp.size())
    g[i].was = 0;
    int pred = 0;
    rep(i,0,mp.size())
    {
        int v = vec[i];
        if (!g[v].was)
        {
            Res[pred] = pii(1e9, 1e9);
            dfs(v, pred);
            ++pred;
        }
        
    }
    rep(i,0,mp.size())
    rep(j,0,g[i].inc.size())
    {
        to[g[i].pred].push_back(g[g[i].inc[j]].pred);
    }
    rep(i,0,pred)
    {
        if (!was[i])
            dfs2(i);
    }
    //
    ll sumR = 0;
    ll sumL = 0;
    rep(i,0,n)
    {
        sumR += Res[g[A[i]].pred].first;
        sumL += Res[g[A[i]].pred].second;
    }
    cout<<sumR<<' '<<sumL<<endl;
}

//#define prob "path"


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}