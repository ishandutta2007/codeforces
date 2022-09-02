#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000000;

int n; 
int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int tot = 0;
    REP(i, 0, n)
    {
        scanf("%d", a + i);
        tot += a[i];
    }
    sort(a, a + n, greater<int>());
    int now = 0;
    REP(i, 0, n) now += abs(3 - a[i]);
    int j = n;
    int ans = oo;
    for (int i = 0; i <= n; now -= abs(3 - a[i]), now += abs(4 - a[i]), ++i)
    {
        if (i * 4 > tot) break;
        if ((tot - (i * 4)) % 3) continue;
        int val = i + (tot - i * 4) / 3;
        if (val > n) continue;
        while (j > val) --j, now -= abs(3 - a[j]), now += a[j];
        assert(!(now & 1));
        chkmin(ans, now >> 1);
    }
    printf("%d\n", ans == oo ? -1 : ans);
    return 0;
}