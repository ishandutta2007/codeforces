#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a, b, p, q;
int tst;
const int A = sqrt((int)1e9);
pair < int, int > best;
void upd(int x) {
    int val = abs(2 * ((1LL * p * x) % q) - q);
    best = min(best, make_pair(val, x));
}
void solve() {
    cin >> a >> b >> p >> q;
    best = make_pair(q + 1000, -1);
    while (b % A != (A - 1)) {
        upd(b);
        b--;
        if (b < a) break;
    }
    while (a % A != 0) {
        upd(a);
        a++;
        if (b < a) break;
    }
    if (b < a) {
        cout << best.second << '\n';
        return;
    }
    int l = a / A;
    int r = b / A;
    vector < pair < unsigned int, int > > f1, f2;
    for (int i = l; i <= r; i++) {
        f1.push_back(make_pair((1LL * p * A * i) % q, i));
    }
    for (int i = 0; i < A; i++) {
        f2.push_back(make_pair((1LL * p * i) % q, i));
    }
    sort(f1.begin(), f1.end());
    vector < pair < unsigned int, int > > nf1, nf2;
    for (int i = 0; i < f1.size(); i++) {
        if (i > 0 && f1[i].first == f1[i - 1].first) continue;
        nf1.push_back(f1[i]);
    }
    f1 = nf1;
    sort(f2.begin(), f2.end());
    for (int i = 0; i < f2.size(); i++) {
        if (i > 0 && f2[i].first == f2[i - 1].first) continue;
        nf2.push_back(f2[i]);
    }
    f2 = nf2;
    int ri = 0;
    unsigned int qq = q;
    reverse(f1.begin(), f1.end());
    for (int i = 0; i < f1.size(); i++) {
        while (ri < f2.size() && 2 * (f1[i].first + f2[ri].first) < qq) ri++; ri--;
        ri = max(ri, 0);
        for (int j = ri; j <= ri + 1; j++) {
            if (j >= 0 && j < f2.size()) {
                upd(f1[i].second * A + f2[j].second);
            }
        }
    }
    ri = 0;
    for (int i = 0; i < f1.size(); i++) {
        while (ri < f2.size() && (2 * (f1[i].first + f2[ri].first)) < 3 * qq) {
            ri++;
        }
        ri--;
        ri = max(ri, 0);
        for (int j = ri; j <= ri + 1; j++) {
            if (j >= 0 && j < f2.size()) {
                upd(f1[i].second * A + f2[j].second);
            }
        }
    }
    cout << best.second << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}