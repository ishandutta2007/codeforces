#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif


#include <iostream>
#include <iomanip>
#include <cstdio>
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

map<int,int> buff[200100];
int mppos = 0;

struct node
{
    int x,y;
    int sum;
    int cnt;
    node *left, *right;
    void init(int x0, int y0,int cnt0)
    {
        x = x0;
        y = y0;
        cnt = cnt0;
        sum  = cnt0;
        left = right = 0;
    }
} nbuff[2000100];

int npos = 0;

inline int getSum(node *v)
{
    return v ? v->sum : 0;
}

inline void recalc(node *v)
{
    if (v == 0)
        return ;
    v->sum = v->cnt + getSum(v->left) + getSum(v->right);
}

node *merge(node *L,node *R)
{
    if (L == 0)
        return R;
    if (R == 0)
        return L;
    if (L->y > R->y)
    {
        L->right = merge(L->right, R);
        recalc(L);
        return L;
    }
    R->left = merge(L, R->left);
    recalc(R);
    return R;
}

void split(node *v, node *&L, node *&R, int x)
{
    if (v==0)
    {
        L = R = 0;
        return;
    }
    if (v->x < x)
    {
        split(v->right, v->right,R,x);
        L = v;
        recalc(L);
        return;
    }
    split(v->left, L, v->left,x);
    R = v;
    recalc(R);
}

bool addIfEx(node *v, int x, int val)
{
    if (v == 0)
        return false;
    if (v->x == x)
    {
        v->cnt += val;
        v->sum += val;
        return true;
    }
    bool res;
    if (v->x < x)
        res = addIfEx(v->right,x,val);
    else
        res = addIfEx(v->left, x, val);
    if (res)
        recalc(v);
    return res;
}


void add(node *&v,int x,int y,int cnt)
{
    node *add = nbuff + npos++;
    add->init(x,y,cnt);
    node *L,*R;
    split(v,L,R,x);
    L = merge(L,add);
    v = merge(L,R);
}


struct vert
{
    vector<int> inc;
    vector<pii> qs;
    int col;
    map<int,int> *mp;
    node *tr;
    vert()
    {
        tr = 0;
        mp = 0;
    }
} g[200100];

//void print(node *v)
//{
//    if (v==0)
//        return;
//    print(v->left);
//    fprintf(stderr,"[%d, %d, %d], ",v->x, v->cnt,v->sum);
//    print(v->right);
//}

void vertMerge(int a,int b)
{
    map<int,int> *mpa = g[a].mp;
    map<int,int> *mpb = g[b].mp;
    node *tra = g[a].tr, *trb = g[b].tr;
    if (mpa == 0)
    {
        g[a].mp = mpb;
        g[a].tr = trb;
        return;
    }
    if (mpa->size() < mpb->size())
    {
        swap(mpa,mpb);
        swap(tra,trb);
    }
    for (map<int,int>::iterator iter = mpb->begin(); iter!= mpb->end(); ++iter)
    {
        map<int,int>::iterator ita = mpa->find(iter->first);
        int ina = 0;
        if (ita != mpa->end())
        {
            addIfEx(tra, ita->second, -1);
            ina = ita->second;
            ita->second += iter->second;
        }
        else
        {
            mpa->insert(*iter);
        }
        if (!addIfEx(tra, iter->second + ina, 1))
        {
            add(tra, iter->second + ina,rand(),1);
        }
    }
    g[a].mp = mpa;
    g[a].tr = tra;
}

int Res[100100]={0};
void dfs(int k,int prev)
{
    rep(i,0,g[k].inc.size())
        if (g[k].inc[i] != prev)
        {
            dfs(g[k].inc[i], k);
            vertMerge(k, g[k].inc[i]);
        }
    if (g[k].mp == 0)
    {
        g[k].mp = buff + mppos++;
        g[k].tr = 0;
    }
    g[k].mp->operator[](g[k].col)++;
    int newCnt = g[k].mp->operator[](g[k].col);
    addIfEx(g[k].tr, newCnt-1, -1);
    if (!addIfEx(g[k].tr, newCnt, 1))
    {
        add(g[k].tr, newCnt, rand(),1);
    }
    rep(i,0,g[k].qs.size())
    {
        node *L,*R;
        split(g[k].tr, L, R, g[k].qs[i].first);
        Res[g[k].qs[i].second] = getSum(R);
        g[k].tr = merge(L,R);
    }
}

void run()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,n)
    {
        scanf("%d",&g[i].col);
    }
    rep(i,0,n-1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].inc.push_back(b);
        g[b].inc.push_back(a);
    }
    rep(i,0,m)
    {
        int v,k;
        scanf("%d%d",&v,&k);
        --v;
        g[v].qs.push_back(pii(k,i));
    }
    dfs(0,-1);
    rep(i,0,m)
    printf("%d\n",Res[i]);
    puts("");
}

//#define prob "kids"

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
    printf("\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}