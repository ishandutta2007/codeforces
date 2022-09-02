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

const int maxn = 200000;

int n;

int sum[maxn + 5];
int a[maxn + 5];

LL ans = 0;

inline void work(const int &l)
{
    int tmp = n / l;
    REP(i, 1, tmp + 1) 
    {
        sum[i] = __gcd(i, tmp) == 1;
        sum[i] += sum[i - 1];
    }
    static int Max[maxn + 5];
    REP(i, 0, l) 
    {
        int &ma = Max[i];
        ma = 0;
        for (int j = i; j < n; j += l) chkmax(ma, a[j]);
    }
    static bool ok[maxn + 5];
    REP(i, 0, n) ok[i] = a[i] == Max[i % l];
    int lst = n << 1;
    REP(i, 0, n) 
        if (!ok[i])
        {
            lst = n + i;
            break;
        }
    for (int i = n - 1; i >= 0; --i)
    {
        chkmin(lst, i + n - 1);
        if (!ok[i]) lst = i;
        else ans += sum[(lst - i) / l];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", a + i);
    REP(i, 1, n) if (n % i == 0) work(i);
    cout << ans << endl;
    return 0;
}