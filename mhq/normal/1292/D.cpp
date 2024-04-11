#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
#define y0 gsjdlgskdg
const int maxN = 5005;
int n;
int lp[maxN];
const int maxSZ = 700;
int cnt[maxN];
const int TOT = 2 * maxN;
int ex[TOT][maxSZ];
int sm[TOT][maxSZ];
uint pref[TOT][maxSZ];
mt19937 rnd(228);
uint f[maxSZ];
int frst[TOT];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < maxSZ; i++) {
        f[i] = rnd() | (rnd() << 16);
    }
    vector < int > primes;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < maxN; j += i) {
                lp[j] = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) x = 1;
        cnt[x]++;
    }
    reverse(primes.begin(), primes.end());
    int SZ = primes.size();
    for (int i = 1; i < maxN; i++) {
        for (int t = 0; t < SZ; t++) {
            ex[i][t] = ex[i - 1][t];
        }
        int c = i;
        for (int t = 0; t < SZ; t++) {
            if (c % primes[t] == 0) {
                while (c % primes[t] == 0) {
                    ex[i][t]++;
                    c /= primes[t];
                }
            }
        }
    }
    int cur_sz = maxN;
    for (int i = 1; i + 1 < maxN - 1; i++) {
        for (int j = 0; j < SZ; j++) {
            if (ex[i][j] != ex[i + 1][j]) {
                ex[cur_sz][j] = ex[i][j];
                break;
            }
        }
        cur_sz++;
    }
    cur_sz--;
    for (int i = 1; i <= cur_sz; i++) {
        frst[i] = -1;
        for (int j = 0; j < SZ; j++) {
            pref[i][j] = ex[i][j] * f[j];
            sm[i][j] = ex[i][j];
            if (ex[i][j] && frst[i] == -1) frst[i] = j;
            if (j) {
                pref[i][j] += pref[i][j - 1];
                sm[i][j] += sm[i][j - 1];
            }

        }
    }
    const ll INF = 1e18;
    ll best = INF;
    for (int i = 1; i <= cur_sz; i++) {
        ll val = 0;
        for (int j = 1; j < maxN; j++) {
            if (pref[i][SZ - 1] == pref[j][SZ - 1]) continue;
            int l = -1;
            int r = SZ - 1;
            if (frst[i] != frst[j]) {
                r = min(frst[i], frst[j]);
            }
            else {
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (pref[i][mid] != pref[j][mid]) r = mid;
                    else l = mid;
                }
            }
            // v r ploho
            val += 1LL * cnt[j] * (abs(ex[i][r] - ex[j][r]) + (sm[i][SZ - 1] - sm[i][r]) + (sm[j][SZ - 1] - sm[j][r]));
        }
        best = min(best, val);
    }
    cout << best;
    return 0;
}