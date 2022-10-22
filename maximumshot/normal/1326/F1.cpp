#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 14;

int cl[1 << (N / 2)][N];
int cr[1 << (N / 2)][N];
int pl[N], sl;
int pr[N], sr;
int dp[1 << (N / 2)][N][2];

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
//    n = 14;

    vector<vector<int>> g(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j] = s[j] - '0';
//            g[i][j] = i == j ? 0 : 1;
        }
    }

    int nl = n / 2;
    int nr = n - nl;

    vector<ll> f(1 << n);

    int N1 = 1 << n;
    int N2 = 1 << (n - 1);
    int TL = (1 << (nl - 1)) - 1;
    int TR = (1 << (nr - 1)) - 1;

    for (int mask = 0; mask < N1; mask++) {
        if (__builtin_popcount(mask) != nl) {
            continue;
        }

        fill((int*) cl, (int*) cl + (1 << (N / 2)) * N, 0);
        fill((int*) cr, (int*) cr + (1 << (N / 2)) * N, 0);

        sl = sr = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask)
                pl[sl++] = i;
            else
                pr[sr++] = i;
        }

        do {
            int pmask = 0;
            for (int i = 0; i + 1 < nl; i++)
                if (g[pl[i]][pl[i + 1]])
                    pmask |= (1 << i);
            cl[pmask][pl[sl - 1]]++;
        } while (next_permutation(pl, pl + sl));

        do {
            int pmask = 0;
            for (int i = 0; i + 1 < nr; i++)
                if (g[pr[i]][pr[i + 1]])
                    pmask |= (1 << i);
            cr[pmask][pr[0]]++;
        } while (next_permutation(pr, pr + sr));

        // int dp[1 << (N / 2)][N][2];

        fill((int*) dp, (int*) dp + (1 << (N / 2)) * N * 2, 0);

        for (int rmask = 0; rmask <= TR; rmask++) {
            for (int m = 0; m < 2; m++) {
                for (int il = 0; il < sl; il++) {
                    int u = pl[il];
                    for (int ir = 0; ir < sr; ir++) {
                        int v = pr[ir];
                        if (g[u][v] == m)
                            dp[rmask][u][m] += cr[rmask][v];
                    }
                }
            }
        }

        for (int i = 0; i < N2; i++) {
            int m = (i >> (nl - 1)) & 1;

            int lmask = i & TL;
            int rmask = (i >> nl) & TR;

//            cout << i << " : " << lmask << " " << m << " " << rmask << "\n";

            for (int il = 0; il < sl; il++) {
                int x = cl[lmask][pl[il]];
                if (!x)
                    continue;
                int y = dp[rmask][pl[il]][m];
                f[i] += 1ll * x * y;
            }
        }
    }

    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
        cout << f[mask] << " ";
    }
    cout << "\n";

    return 0;
}