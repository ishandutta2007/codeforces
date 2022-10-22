#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx,tune=native")

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int SEGCNT = 300;
const int SEGLEN = 100299 / SEGCNT;
int cnt[SEGCNT][10001];
int push[SEGCNT];
int ar[SEGCNT * SEGLEN];

void upd(int segi)
{
    for (int i = segi * SEGLEN; i < (segi + 1) * SEGLEN; ++i)
    {
        --cnt[segi][ar[i]];
        ar[i] += push[segi];
        ++cnt[segi][ar[i]];
    }
    push[segi] = 0;
}

inline bool is_happy(int x)
{
    while (x)
    {
        auto d = div(x, 10);
        if (d.rem != 4 && d.rem != 7)
            return false;
        x = d.quot;
    }
    return true;
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, n)
    {
        scanf("%d", &ar[i]);
        ++cnt[i / SEGLEN][ar[i]];
    }
    For(_, m)
    {
        char s[10];
        scanf(" %s", s);
        if (s[0] == 'a')
        {
            int l, r, val;
            scanf("%d %d %d", &l, &r, &val);
            --l;
            int sl = l / SEGLEN;
            int sr = (r - 1) / SEGLEN;
            for (int i = l; i < r && i / SEGLEN == sl; ++i)
            {
                --cnt[sl][ar[i]];
                ar[i] += val;
                ++cnt[sl][ar[i]];
            }
            upd(sl);
            if (sl != sr)
            {
                for (int i = r - 1; i >= 0 && i / SEGLEN == sr; --i)
                {
                    --cnt[sr][ar[i]];
                    ar[i] += val;
                    ++cnt[sr][ar[i]];
                }
                upd(sr);
            }
            for (int i = sl + 1; i < sr; ++i)
                push[i] += val;
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            --l;
            int res = 0;
            int sl = l / SEGLEN;
            int sr = (r - 1) / SEGLEN;
            for (int i = l; i < r && i / SEGLEN == sl; ++i)
                res += is_happy(ar[i] + push[sl]);
            if (sl != sr)
                for (int i = r - 1; i >= 0 && i / SEGLEN == sr; --i)
                    res += is_happy(ar[i] + push[sr]);
            for (int i = sl + 1; i < sr; ++i)
            {
                if (4 >= push[i]) res += cnt[i][4 - push[i]];
                if (7 >= push[i]) res += cnt[i][7 - push[i]];
                if (44 >= push[i]) res += cnt[i][44 - push[i]];
                if (47 >= push[i]) res += cnt[i][47 - push[i]];
                if (74 >= push[i]) res += cnt[i][74 - push[i]];
                if (77 >= push[i]) res += cnt[i][77 - push[i]];
                if (444 >= push[i]) res += cnt[i][444 - push[i]];
                if (447 >= push[i]) res += cnt[i][447 - push[i]];
                if (474 >= push[i]) res += cnt[i][474 - push[i]];
                if (477 >= push[i]) res += cnt[i][477 - push[i]];
                if (744 >= push[i]) res += cnt[i][744 - push[i]];
                if (747 >= push[i]) res += cnt[i][747 - push[i]];
                if (774 >= push[i]) res += cnt[i][774 - push[i]];
                if (777 >= push[i]) res += cnt[i][777 - push[i]];
                if (4444 >= push[i]) res += cnt[i][4444 - push[i]];
                if (4447 >= push[i]) res += cnt[i][4447 - push[i]];
                if (4474 >= push[i]) res += cnt[i][4474 - push[i]];
                if (4477 >= push[i]) res += cnt[i][4477 - push[i]];
                if (4744 >= push[i]) res += cnt[i][4744 - push[i]];
                if (4747 >= push[i]) res += cnt[i][4747 - push[i]];
                if (4774 >= push[i]) res += cnt[i][4774 - push[i]];
                if (4777 >= push[i]) res += cnt[i][4777 - push[i]];
                if (7444 >= push[i]) res += cnt[i][7444 - push[i]];
                if (7447 >= push[i]) res += cnt[i][7447 - push[i]];
                if (7474 >= push[i]) res += cnt[i][7474 - push[i]];
                if (7477 >= push[i]) res += cnt[i][7477 - push[i]];
                if (7744 >= push[i]) res += cnt[i][7744 - push[i]];
                if (7747 >= push[i]) res += cnt[i][7747 - push[i]];
                if (7774 >= push[i]) res += cnt[i][7774 - push[i]];
                if (7777 >= push[i]) res += cnt[i][7777 - push[i]];
            }
            printf("%d\n", res);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}