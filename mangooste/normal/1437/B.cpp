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
        int n;
        string s;
        cin >> n >> s;

        int ans1 = 0;
        int ans2 = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1' && s[i] == s[i - 1]) {
                ans1++;
            }
            if (s[i] == '0' && s[i] == s[i - 1]) {
                ans2++;
            }
        }

        cout << max(ans1, ans2) << '\n';
    }
}