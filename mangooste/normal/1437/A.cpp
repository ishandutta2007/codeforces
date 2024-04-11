#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
#define pb emplace_back

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nCases;
    cin >> nCases;
    while (nCases--) {
        ll l, r;
        cin >> l >> r;
        l *= 2;
        r *= 2;

        if (l * 2 > r) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}