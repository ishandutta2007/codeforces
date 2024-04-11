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


const int SZ = 100100;
struct node
{
    int y;
    int vertInd;
    int val;
    int mx;
    int mxVertInd;
    int cnt;
    node *left, *right;
    void init(int val0, int vertInd0)
    {
        y = rand();
        val = val0;
        mx = val0;
        cnt = 1;
        vertInd = vertInd0;
        mxVertInd = vertInd0;
        left = right = 0;
    }
} buff[SZ];
int bsize = 0;

const int INF = 1e9/2;
int getMax(node *v)
{
    return v ? v->mx : -INF;
}

int getCnt(node *v)
{
    return v ? v->cnt : 0;
}

void recalc(node *v)
{
    if (v==0) return;
    v->mx = v->val;
    v->mxVertInd = v->vertInd;
    if (v->left && v->left->mx > v->mx)
    {
        v->mx = v->left->mx;
        v->mxVertInd = v->left->mxVertInd;
    }
    if (v->right && v->right->mx > v->mx)
    {
        v->mx = v->right->mx;
        v->mxVertInd = v->right->mxVertInd;
    }
    v->cnt = getCnt(v->left) + getCnt(v->right)  + 1;
}

node *merge(node *L, node *R)
{
    if (L == 0)
        return R;
    if (R == 0)
        return L;
    if (L->y  > R->y)
    {
        L->right = merge(L->right, R);
        recalc(L);
        return L;
    }
    R->left = merge(L, R->left);
    recalc(R);
    return R;
}

void split(node *v, node* &L, node* &R, int x)
{
    if (v == 0)
    {
        L = R = 0;
        return;
    }
    if (getCnt(v->left) < x)
    {
        split(v->right, v->right, R, x - getCnt(v->left) - 1);
        recalc(v);
        L = v;
        return;
    }
    split(v->left, L, v->left, x);
    recalc(v);
    R = v;
}

int minLen, maxLen;
bool exist;
int ansA, ansB;
void uni(node *&L, int &addL, node *&R, int &addR)
{
    if (L == 0)
    {
        L = R;
        addL = addR;
        return;
    }
    if (getCnt(L) < getCnt(R))
    {
        swap(L,R);
        swap(addL, addR);
    }
    node *newR = 0;
    rep(i,0,getCnt(R))
    {
        node *curr;
        split(R,curr,R,1);
        node *A, *B, *pos;
        //
        split(L, A, B,   maxLen - (i+1));
        split(A, A, pos, minLen - (i+1) - 1);
        if (getMax(pos) + addL + getMax(curr) + addR >= 0)
        {
            exist = true;
            ansA = pos->mxVertInd;
            ansB = curr->mxVertInd;
        }
        A = merge(A, pos);
        L = merge(A, B);
                newR = merge(newR, curr);
    }
    R = newR;
    rep(i,0,getCnt(R))
    {
        node *curr;
        split(R,curr,R,1);
        node *A, *B, *pos;
        split(L, A,B, i+1);
        split(A, A, pos, i);
//        printf("!%d %d\n",pos->val + addL , curr->val + addR);
        if (pos->val + addL < curr->val + addR)
            pos->init(curr->val + addR - addL, curr->vertInd);
        A = merge(A, pos);
        L = merge(A, B);
    }
}

struct vert
{
    vector<pii> inc;
    node *T;
    int add;
    bool was;
} g[100100];

int mnVal;
void dfs(int k)
{
    if (exist) return;
    g[k].was = 1;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i].first;
        int w = g[k].inc[i].second;
        if (!g[to].was)
        {
            dfs(to);
            int edgeVal = w >= mnVal ? 1 : -1;
//            if (k == 0)
//            {
//                printf("%d) g[to].add = %d, edge = %d\n", k, g[to].add, edgeVal);
//            }
            g[to].add += edgeVal;
            node *edge = buff + bsize++;
            edge->init(edgeVal - g[to].add, to);
            g[to].T = merge(edge, g[to].T);
            uni(g[k].T, g[k].add, g[to].T, g[to].add);
        }
    }

    node *L, *R, *M;
    split(g[k].T, L, R, maxLen);
    split(L, L, M, minLen - 1);
//    printf("k = %d\n", k);
//    printf("%d %d %d\n", getCnt(L), getCnt(M), getCnt(R));
//    printf("Mmax = %d\n", getMax(M) + g[k].add);
    if (getMax(M) + g[k].add >= 0)
    {
        exist = true;
        ansA = M->mxVertInd;
        ansB = k;
    }
    L = merge(L,M);
    g[k].T = merge(L,R);
}

bool can(int val, int n)
{
    bsize = 0;
    mnVal = val;
    rep(i,0,n)
    {
        g[i].was = 0;
        g[i].T = 0;
        g[i].add = 0;
    }
    exist = false;
    dfs(0);
    return exist;
}

void run()
{
    int n;
    cin>>n>>minLen>>maxLen;
    int W[SZ];
    rep(i,0,n-1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a;--b;
        g[a].inc.push_back(pii(b,c));
        g[b].inc.push_back(pii(a,c));
        W[i] = c;
    }
    sort(W,W+n-1);
    int res = -1;
    int ansl = -2, ansr = -2;
    int l = 0, r = n-2;
//    l = 0; r = 0; W[0] = 8;
    while (l<=r)
    {
        int c = (l+r)/2;
        if (can(W[c], n))
        {
            res = c;
            ansl = ansA;
            ansr = ansB;
            l = c + 1;
        }
        else
            r = c - 1;
    }
//    cout<<res<<' '<<W[res]<<endl;
    printf("%d %d\n", ansl+1, ansr+1);
    
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