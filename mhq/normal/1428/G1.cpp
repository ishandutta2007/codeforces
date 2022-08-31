#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int k;
ll f[6];
int dig[6];
const int maxN = 1e6 + 10;
ll dp[maxN];
ll combine(ll x, ll y) {
    return max(x, y);
}

const ll INF = 1e17;
struct Tqueue{
    vector < ll >  st1, st2;
    vector < ll > data;
    Tqueue() {
        st1 = {-INF};
        st2 = {-INF};
    }
    void add(ll x) {
        data.emplace_back(x);
        st1.emplace_back(combine(x, st1.back()));
    }
    void del() {
        if (st2.size() > 1) {
            st2.pop_back();
        }
        else {
            assert(st1.size() > 1);
            st1.resize(1);

            for (int i = data.size() - 1; i >= 0; i--) {
                st2.emplace_back(combine(st2.back(), data[i]));
            }
            data.clear();
            st2.pop_back();
        }
    }
    ll get() {
        return combine(st1.back(), st2.back());
    }
};
ll ndp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> f[i];
    }
    int q;
    cin >> q;
    assert(q == 1);
    int n;
    cin >> n;
    int tn = n;
    for (int i = 0; i < 6; i++) {
        dig[i] = (tn % 10);
        tn /= 10;
    }
    for (int j = 0; j <= n; j++) dp[j] = -INF;
    dp[0] = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= n; j++) {
            ndp[j] = -INF;
        }
        vector<Tqueue> r(3);
        for (int j = 0; j <= n; j++) {
            r[j % 3].add(dp[j] - (j / 3) * (ll)f[i]);
            if (j - 9 * (k - 1) - 3 >= 0) r[j % 3].del();
            for (int a = 0; a < 3; a++) {
                if (j % 3 >= a) {
                    ndp[j] = max(ndp[j], r[a].get() + (j / 3) * f[i]);
                }
                else {
                    ndp[j] = max(ndp[j], r[a].get() + (j / 3) * f[i] - f[i]);
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int cnt = 9 * (k - 1) + 1; cnt <= 9 * k; cnt++) {
                if (j >= cnt) {
                    if (cnt % 3 == 0) {
                        ndp[j] = max(ndp[j], dp[j - cnt] + (cnt / 3) * f[i]);
                    }
                    else {
                        //??
                        ndp[j] = max(ndp[j], dp[j - cnt] + (3 * (k - 1)) * f[i]);
                    }
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            dp[j] = -INF;
        }
        for (int j = 0; j <= n; j++) {
            if (j % 10 == dig[i]) {
                dp[j / 10] = ndp[j];
            }
        }
    }
    cout << dp[0] << '\n';
    return 0;
}