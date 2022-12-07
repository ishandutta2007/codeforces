/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-09-19
File: K.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 1000005;
const int maxv = 1000000;
struct BIT
{
    LL s[maxn];
    int lim;

    void init(int h){lim = h; for(int i = 1; i <= h; ++ i) s[i] = 0;}

    void add(int p, LL v)
    {
        while(p <= lim)
        {
            s[p] += v;
            p += lowbit(p);
        }
    }
    
    LL cal(int p)
    {
        LL ret = 0;
        while(p > 0)
        {
            ret += s[p];
            p -= lowbit(p);
        }
        return ret;
    }
}bit;

struct SegTree
{
    LL val[maxn << 2], tag[maxn << 2];

    void mt(int o, int lg, int rg)
    {
        if(lg == rg) {val[o] = lg; return;}
        int mid = (lg + rg) >> 1;
        mt(o << 1, lg, mid); mt(o << 1 | 1, mid + 1, rg);
        pushup(o);
    }

    void pushup(int o){val[o] = max(val[o << 1], val[o << 1 | 1]);}

    void pushdown(int o)
    {
        val[o << 1] += tag[o]; tag[o << 1] += tag[o];
        val[o << 1 | 1] += tag[o]; tag[o << 1 | 1] += tag[o];
        tag[o] = 0;
    }

    void add(int o, int lg, int rg, int l, int r, LL v)
    {
        if(lg >= l && rg <= r) {val[o] += v; tag[o] += v; return;}
        pushdown(o); int mid = (lg + rg) >> 1;
        if(l <= mid) add(o << 1, lg, mid, l, min(mid, r), v);
        if(r > mid) add(o << 1 | 1, mid + 1, rg, max(mid + 1, l), r, v);
        pushup(o);
    }   

    LL query(int o, int lg, int rg, int l, int r)
    {
        if(lg >= l && rg <= r) return val[o];
        pushdown(o); int mid = (lg + rg) >> 1;
        LL ret = 0;
        if(l <= mid) ret = max(ret, query(o << 1, lg, mid, l, min(mid, r)));
        if(r > mid) ret = max(ret, query(o << 1 | 1, mid + 1, rg, max(mid + 1, l), r));
        pushup(o); return ret;
    }
}sgt;

char s[3];
pii rec[maxn];
int q, p, d, cnt = 0;

int main()
{
    
    scd(q); bit.init(maxv); sgt.mt(1, 1, maxv);
    while(q --)
    {
        scanf("%s", s); cnt ++;
        if(s[0] == '?')
        {
            scd(p);
            printf("%lld\n", sgt.query(1, 1, maxv, 1, p) - (bit.cal(maxv) - bit.cal(p)) - p);
        }else if(s[0] == '+')
        {
            scd(p); scd(d);
            rec[cnt] = mp(p, d);
            bit.add(p, d); sgt.add(1, 1, maxv, 1, p, d);
        }else
        {
            scd(p); pii t = rec[p];
            p = t.fi; d = t.se;
            bit.add(p, -d); sgt.add(1, 1, maxv, 1, p, -d);
        }
    }
    return 0;
}