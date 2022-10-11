#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

inline vector<int> getCnt(string s) {
    vector<int> cnt(26, 0);
    for (auto &x : s) cnt[x - 'a']++;
    return cnt;
}

inline int getInversions(string s) {
    int ans = 0;
    for (int i = 0; i < sz(s); i++) {
        for (int j = i + 1; j < sz(s); j++) {
            ans += s[i] > s[j];
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a; cin >> a;
        string b; cin >> b;
        vector<int> cntA = getCnt(a);
        vector<int> cntB = getCnt(b);
        if (cntA != cntB) {
            cout << "NO\n";
        } else if (*max_element(all(cntA)) > 1) {
            cout << "YES\n";
        } else if (getInversions(a) % 2 == getInversions(b) % 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}