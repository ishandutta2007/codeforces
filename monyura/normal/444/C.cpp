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

const int SZ = 100100;

struct otr
{
    int a,b,color;
    otr(){}
    otr(int a0, int b0, int c0)
    {
        a = a0;
        b = b0;
        color = c0;
    }
    bool operator<(const otr &other) const
    {
        return a < other.a;
    }
    bool intersec(const otr &other) const
    {
        return max(a, other.a) <= min(b, other.b);
    }
};


ll D[4*SZ] = {0};
ll Add[4*SZ] = {0};


void addToSum(int v, int l, int r, int ql, int qr, int val)
{
    if (l == ql && r==qr)
    {
        Add[v] += val;
        D[v] += ll(val)*(r-l+1);
        return;
    }
    int c = (l+r)/2;
    if (qr <= c)
        addToSum(2*v, l,c,ql,qr,val);
    else if (ql > c)
        addToSum(2*v+1,c+1,r,ql,qr,val);
    else
    {
        addToSum(2*v,l,c,ql,c,val);
        addToSum(2*v+1, c+1, r, c+1, qr, val);
    }
    D[v] = D[2*v] + D[2*v+1] + Add[v]*(r-l+1);
 }

ll getSum(int v, int l, int r, int ql, int qr)
{
    if (l==ql && r==qr)
        return D[v];
    int c = (l+r)/2;
    ll res = 0;
    if (qr <= c)
        res = getSum(2*v,l,c,ql,qr);
    else if (ql > c)
        res = getSum(2*v+1,c+1,r,ql,qr);
    else
    {
        res = getSum(2*v,l,c,ql,c) + getSum(2*v+1,c+1,r,c+1,qr);
    }
    return res + Add[v] * (qr-ql+1);
}

otr toDel[SZ];
int toDelPos;
otr toAdd[SZ];
int toAddPos;

void run()
{
    int n,m;
    cin>>n>>m;
    set<otr> st;
    rep(i,0,n)
    {
        st.insert(otr(i,i,i+1));
    }
//    for (auto p:st)
//        printf("(%d, %d; %d) ", p.a, p.b, p.color);
//    puts("");
    rep(i,0,m)
    {
        int t;
        scanf("%d",&t);
        if (t == 1)
        {
            int ql,qr,val;
            scanf("%d%d%d", &ql, &qr, &val);
            --ql;--qr;
            otr curr(ql,qr,val);
            toDelPos = 0;
            toAddPos =  0;
            auto iter =  st.lower_bound(curr);
            if (iter !=  st.begin())
            {
                --iter;
                if (!iter->intersec(curr))
                {
                    toDel[toDelPos++] = *iter;
                    toAdd[toAddPos++] = *iter;
                    ++iter;
                }
            }
            while (iter !=  st.end() && iter->intersec(otr(curr)))
            {
                toDel[toDelPos++] = *iter;
                if (iter->a < ql)
                    toAdd[toAddPos++] = otr(iter->a, ql-1, iter->color);
                if (qr < iter->b)
                    toAdd[toAddPos++] = otr(qr+1, iter->b, iter->color);
                int l = max(ql, iter->a);
                int r = min(qr, iter->b);
                addToSum(1,0,n-1, l, r, abs(iter->color - val));
                //printf("Add [%d;%d] val %d\n", l, r, abs(iter->color - val));
                ++iter;
            }
            toAdd[toAddPos++] = curr;
            if (iter != st.end())
            {
                toDel[toDelPos++] = *iter;
                toAdd[toAddPos++] = *iter;
            }
            sort(toAdd,toAdd+toAddPos);
//            rep(i,0,toAddPos)
//                printf("[%d %d %d] ", toAdd[i].a, toAdd[i].b, toAdd[i].color);
//            puts("");
            int newAddPos = 1;
            rep(i,1,toAddPos)
            {
                if (toAdd[newAddPos-1].b + 1== toAdd[i].a && toAdd[newAddPos-1].color == toAdd[i].color)
                    toAdd[newAddPos-1].b = toAdd[i].b;
                else
                    toAdd[newAddPos++] = toAdd[i];
            }
            rep(i,0,toDelPos)
            st.erase(toDel[i]);
            rep(i,0,newAddPos)
            st.insert(toAdd[i]);
//            for (auto p:st)
//                printf("(%d, %d; %d) ", p.a, p.b, p.color);
//            puts("");
        }
        else
        {
            int ql,qr;
            scanf("%d%d",&ql,&qr);
            --ql;--qr;
            ll res = getSum(1,0,n-1,ql,qr);
            printf("%l""ld\n", res);
        }
    }
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