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

const int SZ = 1000100;
struct node
{
    int y;
    int cnt;
    int ind;
    int val;
    node *left, *right;
    node()
    {
        left = right = 0;
        y = rand();
        cnt = 1;
        ind = val = -1;
    }
} BUFF[SZ];

int getCnt(node *v)
{
    return v ? v->cnt : 0;
}

void recalc(node *v)
{
    if (!v)
        return;
    v->cnt = 1 + getCnt(v->left) + getCnt(v->right);
}

node* merge(node *L, node *R)
{
    if (L == 0)
        return R;
    if (R == 0)
        return L;
    if (L -> y > R -> y)
    {
        L ->right = merge(L->right, R);
        recalc(L);
        return L;
    }
    R->left = merge(L, R->left);
    recalc(R);
    return R;
}

void split(node *v, node *&L, node *&R, int x)
{
    if (v == 0)
    {
        L = R = 0;
        return;
    }
    if (getCnt(v->left) < x)
    {
        split(v->right, v->right, R, x - 1 - getCnt(v->left));
        recalc(v);
        L = v;
        return;
    }
    split(v->left, L, v->left, x);
    recalc(v);
    R = v;
    return;
}

int Res[SZ];
bool used[SZ];
void run()
{
    int n,m;
    cin>>n>>m;
    node *T = 0;
    rep(i,0,n)
    {
        node *add = BUFF + i;
        add->ind = i;
        add->val = -1;
        T = merge(T, add);
    }
    rep(i,0,m)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        node *L,*M, *R;
        split(T,L,R,y);
        split(R, M, R, 1);
        if (M->val == -1)
        {
            if (used[x])
            {
                puts("-1");
                return;
            }
            M->val = x;
            used[x] = 1;
        }
        if (M->val != x)
        {
            puts("-1");
            return;
        }
        T = merge(M, L);
        T = merge(T, R);
    }
    rep(i,0,n)
        if (BUFF[i].val != -1)
        {
            Res[BUFF[i].ind] = BUFF[i].val+1;
        }
    int pos = 0;
    rep(i,0,n)
        if (Res[i] == 0)
        {
            while (used[pos])
                ++pos;
            pos++;
            Res[i] = pos;
        }
    rep(i,0,n)
        printf("%d ",Res[i]);
    puts("");
}


//#define prob "D-large"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}