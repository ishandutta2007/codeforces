#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
ll t;
const int maxN = (int)1e5 + 100;
const ld eps = 1e-12;
int a[maxN], b[maxN];
ld p[maxN];
ld C = 0;
bool cmp(int i, int j) {
    if (abs(p[i] - p[j]) < eps) return a[i] < a[j];
    return p[i] < p[j];
}
const int LG = 40;
ld mat[LG][3][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> t;
    vector < int > f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        C = max(C, b[i] * p[i]);
        f.push_back(i);
    }
    sort(f.begin(), f.end(), cmp);
    vector < int > fin;
    for (int i = 0; i < f.size(); i++) {
        while (!fin.empty() && p[fin.back()] * a[fin.back()] + eps < p[f[i]] * a[f[i]]) fin.pop_back();
        fin.push_back(f[i]);
    }
    ld cur_dp = 0;
    ll cur_t = 0;
    for (int i = 0; i < fin.size(); i++) {
        ld cut_point = 1e100;
        if (i + 1 < fin.size()) {
            cut_point = (p[fin[i]] * a[fin[i]] - p[fin[i + 1]] * a[fin[i + 1]]) / (p[fin[i + 1]] - p[fin[i]]);
        }
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                mat[0][a][b] = 0;
            }
        }
        mat[0][0][0] = 1 - p[fin[i]];
        mat[0][0][1] = C * p[fin[i]];
        mat[0][0][2] = p[fin[i]] * a[fin[i]];
        mat[0][1][1] = mat[0][1][2] = mat[0][2][2] = 1;
        for (int it = 0; it + 1 < LG; it++) {
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    mat[it + 1][a][b] = 0;
                }
            }
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    for (int c = 0; c < 3; c++) {
                        mat[it + 1][a][c] += mat[it][a][b] * mat[it][b][c];
                    }
                }
            }
        }
        for (int it = LG - 1; it >= 0; it--) {
            ll nxt = (cur_t + (1LL << it));
            if (nxt >= t) continue;
            ld will_dp = cur_dp * mat[it][0][0] + cur_t * mat[it][0][1] + mat[it][0][2];
            if (C * nxt - will_dp < cut_point) {
                cur_t = nxt;
                cur_dp = will_dp;
            }
        }
        if (C * cur_t - cur_dp < cut_point) {
            cur_dp = cur_dp * (1 - p[fin[i]]) + p[fin[i]] * (a[fin[i]] + C * cur_t);
            cur_t++;
        }
        if (cur_t == t) break;
    }
    cout << fixed << setprecision(12) << cur_dp;
    return 0;
}