#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 30000, max0 = 4;

int n, qn;
LL a[maxn + 5], b[maxn + 5];

int posa[maxn + 5], posb[maxn + 5], rk[maxn + 5];
int id[maxn + 5];
int lk[maxn + 5];

bool ok[maxn + 5];

inline bool cmpa(const int &x, const int &y) { return a[x] > a[y]; }
inline bool cmpb(const int &x, const int &y) { return b[x] > b[y]; }

inline void init()
{
    scanf("%d%d", &n, &qn);
    REP(i, 0, n) scanf("%I64d", a + i), posa[i] = i;
    REP(i, 0, n) scanf("%I64d", b + i), posb[i] = i;
    REP(i, 0, n) id[i] = i;
}

LL best[maxn + 5][max0];
LL dp[maxn + 5];

inline void calc(const int &x)
{
    REP(i, 0, max0)
    {
        if (x - i < 0) best[x][i] = LLONG_MIN;
        else
        {
            best[x][i] = LLONG_MIN;
            int l = i + 1;
            int st = x - i;
            int pos[max0];
            REP(j, 0, l) pos[j] = j;
            do
            {
                LL tmp = 0;
                REP(j, 0, l)
                {
                    int x = st + j, y = st + pos[j];
                    if (id[posa[x]] == posb[y]) 
                    {
                        tmp = LLONG_MIN;
                        break;
                    }
                    tmp += a[posa[x]] * b[posb[y]];
                }
                chkmax(best[x][i], tmp);
            }
            while (next_permutation(pos, pos + l));
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    sort(posa, posa + n, cmpa);
    sort(posb, posb + n, cmpb);
    REP(i, 0, n) rk[posa[i]] = i;
    REP(i, 0, n) calc(i);
    REP(i, 0, qn)
    {
        static int x, y;
        scanf("%d%d", &x, &y), --x, --y;
        swap(id[x], id[y]);
        REP(i, 0, max0) 
		{
			if (rk[x] + i < n) calc(rk[x] + i);
			if (rk[y] + i < n) calc(rk[y] + i);
		}
        dp[0] = 0;
        REP(i, 1, n + 1)
        {
            dp[i] = LLONG_MIN;
			if (i >= 1) chkmax(dp[i], dp[i - 1] + best[i - 1][0]);
			if (i >= 2) chkmax(dp[i], dp[i - 2] + best[i - 1][1]);
			if (i >= 3) chkmax(dp[i], dp[i - 3] + best[i - 1][2]);
			if (i >= 4) chkmax(dp[i], dp[i - 4] + best[i - 1][3]);
			assert(max0 == 4);
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}