#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>
#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
int get(int a, const int &n, const int &p)
{
    a %= p;
    int t = (LL)a * n / p;
    if (!t) return max(p - a * n, a);
    if ((LL)a * n % p < p - p % a - a) --t;
    return get(a - p % a, t, a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, n, p, h;
        scanf("%d%d%d%d", &a, &n, &p, &h);
        a %= p;
        puts(((LL)a * n < p ? a : get(a, n, p)) > h ? "NO" : "YES");
    }
    return 0;
}