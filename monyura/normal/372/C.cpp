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


const ll INF = 1e18;
struct QueueMax
{
    vector<pll> tail;
    vector<pll> head;
    ll getMax()
    {
        ll res = -INF;
        if (tail.size() != 0)
            res = tail.back().second;
        if (head.size() != 0)
            res = max (res, head.back().second);
        return res;
    }
    void pop()
    {
        if (head.size() == 0)
        {
            ll mx = -INF;
            rep(i,0,(int)tail.size())
            {
                ll val = tail[tail.size()-1-i].first;
                mx = max(val,mx);
                head.push_back(pll(val,mx));
            }
            tail.clear();
        }
        head.pop_back();
    }
    void push(ll val)
    {
        ll mx = val;
        if (tail.size() != 0)
            mx = max(mx, tail.back().second);
        tail.push_back(pll(val,mx));
    }
    void clear()
    {
        tail.clear();
        head.clear();
    }
    void print()
    {
        printf("tail:\n");
        rep(i,0,tail.size())
        printf("(%lld,%lld) ",tail[i].first,tail[i].second);
        printf("\nhead:\n");
        rep(i,0,tail.size())
        printf("(%lld,%lld) ",head[i].first,head[i].second);
        puts("");

    }
};


void run()
{
    int n,m,d;
    cin>>n>>m>>d;
    QueueMax q;
    ll Res[150150] = {0};
    ll NextRes[150150];
    int prevT = 1;
    rep(i,0,m)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        --a;
        ll dt = t - prevT;
        ll canGo = d * dt;
        ll stP = - canGo;
        ll endP = canGo;
        q.clear();
        rep(j,0,(int)min(endP+1,(ll)n))
            q.push(Res[j]);
        rep(x,0,n)
        {
            ll curr = q.getMax() + b - mabs(a-x);
//            if (i ==1 && x == 48)
//                q.print();
            NextRes[x] = curr;
            if (stP >= 0)
                q.pop();
            if (endP+1 < n)
                q.push(Res[endP+1]);
            ++stP;
            ++endP;
        }
        rep(x,0,n)
            Res[x] = NextRes[x];
//        printf("[%d]\n",i);
//        rep(x,0,n)
//        printf("%d) %lld\n",x,Res[x]);
        prevT = t;
    }
    ll res = -INF;
    rep(x,0,n)
        res = max(res, Res[x]);
    cout<<res<<endl;
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