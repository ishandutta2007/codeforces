#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 105;
ld p[maxN];
int n;
const int BUBEN = (int)1e6 + 100;
//ld q[maxN][BUBEN];
ld cur_coef[maxN];
int cur_val[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    set < pair < ld, int > > all;
    ld cur_pr = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p[i] = (1.0 * x) / 100;
        cur_coef[i] = 1 - p[i];
        cur_pr *= p[i];
        cur_val[i] = 1;
        all.insert(make_pair((p[i] * 2 - p[i] * p[i]) / p[i], i));
    }
    ld ans = n;
    for (int i = 0; i < BUBEN; i++) {
        ans += 1 - cur_pr;
        auto it = --all.end();
        auto t = *it;
        all.erase(it);
        int ind = t.second;
        cur_pr /= (1 - cur_coef[ind]);
        cur_coef[ind] *= (1 - p[ind]);
        cur_val[ind]++;
        cur_pr *= (1 - cur_coef[ind]);
        all.insert(make_pair((1 - (cur_coef[ind]) * (1 - p[ind])) / (1 - cur_coef[ind]), ind));
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}