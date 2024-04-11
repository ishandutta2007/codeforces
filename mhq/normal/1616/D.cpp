#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e4 + 10;
ll a[maxN];
int dp[maxN];
ll pref[maxN];
int F[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll x;
        cin >> x;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (a[i] - x);
        }
        for (int i = 0; i <= n; i++) {
            F[i] = -1e9;
        }
        F[0] = 0;
        int max_l = 1;
        multiset<int> ss;
        for (int i = 1; i <= n; i++) {

            if (i == 1) {
                ss.insert(-1);
            }
            else {
                ss.insert(F[i - 2] - i);
            }
            F[i] = max(F[i], F[i - 1]);
            if (i >= 2 && pref[i] < pref[i - 2]) {
                while (max_l <= i - 1) {
                    if (max_l == 1) {
                        ss.erase(ss.find(-1));
                    }
                    else {
                        ss.erase(ss.find(F[max_l - 2] - max_l));
                    }
                    max_l++;
                }
            }
            if (i >= 3 && pref[i] < pref[i - 3]) {
                while (max_l <= i - 2) {
                    if (max_l == 1) {
                        ss.erase(ss.find(-1));
                    }
                    else {
                        ss.erase(ss.find(F[max_l - 2] - max_l));
                    }
                    max_l++;
                }
            }
            if (!ss.empty()) {
                F[i] = max(F[i], *(--ss.end()) + i + 1);
            }
            if (i == 1) {
                F[i] = max(F[i], 1);
            }
            else {
                F[i] = max(F[i], 1 + F[i - 2]);
            }
        }
        cout << F[n] << '\n';
    }
    return 0;
}