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
typedef pair<double, double> pdd;

struct node
{
    int x,y;
    node *left, *right;
    int cnt;
    ll sum;
    void init(int x0)
    {
        x = x0;
        y = rand();
        left = right = 0;
        cnt = 1;
        sum = x0;
    }
} buff[100100];
int bcnt = 0;

inline int getCnt(node *v)
{
    return v ? v->cnt : 0;
}

inline ll getSum(node *v)
{
    return v ? v->sum : 0;
}

void recalc(node *v)
{
    if (v==0)
        return;
    v->cnt = 1 + getCnt(v->left) + getCnt(v->right);
    v->sum = v->x + getSum(v->left) + getSum(v->right);
}

node *merge(node *L, node *R)
{
    if (L == 0) return R;
    if (R == 0) return L;
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
    if (v == 0)
    {
        L = R = 0;
        return;
    }
    if (v->x < x)
    {
        split(v->right, v->right, R, x);
        recalc(v);
        L = v;
        return;
    }
    split(v->left, L, v->left, x);
    recalc(v);
    R = v;
}

ll sumOfFirst(node *v, int k)
{
    if (getCnt(v) <= k)
        return getSum(v);
    if (getCnt(v->left) >= k)
        return sumOfFirst(v->left, k);
    return getSum(v->left) + v->x + sumOfFirst(v->right, k - getCnt(v->left) - 1);
}

void add(node *&v, int x)
{
    node *L, *R, *added = buff + bcnt++;
    added->init(x);
    split(v, L, R, x);
    L = merge(L,  added);
    v = merge(L, R);
}




void run()
{
    int n;
    cin>>n;
    vector<int> vec[100100];
    rep(i,0,n)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        vec[a].push_back(b);
    }
    ll otr[100100] = {0};
    int Cnt[100100] = {0};
    rep(i,1,100100)
    {
        ll sum = 0;
        int cnt = 0;
        sort(all(vec[i]), greater<int>());
        for (int j = (int)vec[i].size()-1;j>=0;j--)
        {
            sum += vec[i][j];
            cnt++;
            Cnt[j+1] += cnt;
            otr[j+1] += sum;
        }
    }
    set<int> active;
    rep(i,1,100100)
        if (vec[i].size() >= 1)
            active.insert(i);
    ll res = 1e18;
    node *T = 0;
    vector<int> toDel;
    rep(i,1,100100)
    {
        ll here = otr[i];
        int me = Cnt[i] + vec[0].size();
        int need = max(0, i - me);
        here += sumOfFirst(T, need);
        toDel.clear();
        for (auto pos : active)
        {
            if (vec[pos].size() >= i)
                add(T, vec[pos][i-1]);
            else
                toDel.push_back(pos);
        }
        for (auto del : toDel)
            active.erase(del);
        res = min(res, here);
    }
    cout<<res<<endl;
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