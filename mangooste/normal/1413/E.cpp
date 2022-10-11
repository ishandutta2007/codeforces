#include <bits/stdc++.h>

using namespace std;

#define ts to_string
#define sts string ts
sts(string s) { return s; }
sts(bool b) { return b ? "true" : "false"; }
sts(char c) { return string(1, c); }
sts(const char* s) { return (string) s; }
template<class A, class B> sts(pair<A, B>);
template<class T> sts(T v) { string s = "{", sep = ""; for (auto x : v) { s += sep; sep = ", "; s += ts(x); } return s + "}"; }
template<class A, class B> sts(pair<A, B> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
void dbgPrint() { cerr << endl; }
template<class A, class... B> void dbgPrint(A a, B... b) { cerr << " " << ts(a); dbgPrint(b...); }
#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long e = a - c * b;
        dbg(e);
        if (c < d) {
            if (e > 0) {
                cout << "-1\n";
            } else {
                cout << a << '\n';
            }
            continue;
        }

        long long num = c / d;
        assert(num > 0);
        dbg(num);

        long long A = e;
        dbg(A);

        if (A > 0) {
            cout << "-1\n";
        } else {
            long long A2 = -b * d;
            long long B2 = 2 * a + b * d;
            assert(A2 < 0);
            dbg(A2, B2);

            long long ans = a;

            if (A2 != 0) {
                long long bestK = -B2 / (2 * A2);
                dbg(bestK);
                for (long long i = bestK - 5; i <= bestK + 5 && i <= num + 1; i++) {
                    if (i > 0) {
                        ans = max(ans, (i * i * A2 + B2 * i) / 2);
                    }
                }
            }

            cout << ans << '\n';
        }
    }
}