/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-10-15
File: C.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

#define IN freopen("C.in", "r", stdin)
#define OUT freopen("C.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 250005;
pii a[maxn]; int n;
LL cnt[maxn];

int find(int bg, int label, int ed)
{
    int ret = bg, flag = (label == 1 ? a[bg].fi : a[bg].se);
    for(int i = bg; i <= ed; ++ i)
    {
        int val = (label == 1 ? a[i].fi : a[i].se);
        if(val == flag) { ret = i; } else break;
    }
    return ret;
}

LL cal1()
{
    int l = 1;
    LL s1 = 0, s2 = 0, ret = 0;
    while(l <= n)
    {
        int r = find(l, 1, n);
        LL len = r - l + 1;
        l = r + 1;
        ret += len * s2;
        s2 += len * s1;
        s1 += len;
    }
    return ret;
}

LL cal3()
{
    LL ret = 0;
    int l = 1;
    while(l <= n)
    {
        int r = find(l, 1, n);
        int ll = l;
        LL s1 = 0, s2 = 0;
        while(ll <= r)
        {
            int rr = find(ll, 2, r);
            LL len = rr - ll + 1;
            ll = rr + 1;
            ret += len * s2;
            s2 += len * s1;
            s1 += len;
        }
        l = r + 1;
    }
    return ret;
}

LL cal2()
{
    for(int i = 0; i <= n; ++ i) cnt[i] = 0;
    LL ret = 0, sum = 0;
    int l = 1;
    while(l <= n)
    {
        int r = find(l, 1, n), ll = l;
        LL s1 = 0, sl = 0;
        while(ll <= r)
        {
            int rr = find(ll, 2, r);
            LL len = rr - ll + 1;
            ret += len * s1 - len * sl * cnt[a[rr].se];
            s1 += (sum - cnt[a[rr].se]) * len;
            sl += len;
            ll = rr + 1;
        }
        for(int i = l; i <= r; ++ i) { cnt[a[i].se] ++; sum ++; }
        l = r + 1;
    }
    return ret;
}

LL solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a + 1, a + n + 1);
    LL ans = cal1() + cal3();
    ans += cal2();
    reverse(a + 1, a + n + 1);
    ans += cal2();
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        printf("%lld\n", ans);
    }
    return 0;
}