#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld  ;
const int maxN = 10;
int l[maxN], r[maxN];
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ld ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i - 1] >> r[i - 1];
    }
    for (int i = 1; i <= 10000; i++) {
        for (int mask = 1; mask < (1 << n); mask++) {
            if ((mask & (mask - 1)) == 0) continue;
            ld prob = 1;
            ld coef = 1;
            ld other_prob = 0;
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) {
                    ld cur = 1;
                    for (int bit2 = 0; bit2 < n; bit2++) {
                        if (mask & (1 << bit2)) {
                            if (bit2 == bit) {
                                if (l[bit] >= i + 1) continue;
                                if (r[bit] < (i + 1)) {
                                    cur = 0;
                                    break;
                                }
                                cur *= (1.0 * r[bit] - i - 1 + 1) / (r[bit] - l[bit] + 1);
                            }
                            else {
                                if (l[bit2] > i || r[bit2] < i) {
                                    cur = 0;
                                }
                                cur *= (1.0) / (r[bit2] - l[bit2] + 1);
                            }
                        }
                    }
                    other_prob += cur;
                    if (r[bit] < i) {
                        prob = 0;
                        continue;
                    }
                    else if (l[bit] > i) {
                        prob = 0;
                        continue;
                    }
                    else {
                        prob *= (1.0) / (r[bit] - l[bit] + 1);
                    }
                }
                else {
                    if (l[bit] > i) {
                        coef = 0;
                        break;
                    }
                    else if (r[bit] < i) {
                        continue;
                    }
                    else {
                        coef *= (1.0 * (i - 1 - l[bit] + 1)) / (r[bit] - l[bit] + 1);
                    }
                }
            }
            ans += i * coef * (prob + other_prob);
        }
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}