#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    const int N = 1e7;
    vec<ll> pref(N);
    for (int i = 0; i < N - 1; i++) {
        pref[i + 1] = pref[i] + 2 * i + 1;
    }
    int n;
    cin >> n;
    vec<ll> x(n);
    for (int i = 1; i < n; i += 2) {
        cin >> x[i];
    }
    int cur = 1;
    int before = 0;
    for (int i = 1; i < N && cur < n; i++) {
        int j = lower_bound(all(pref), pref[i] - x[cur]) - pref.begin();
        if (j >= i) {
            cout << "No\n";
            return 0;
        }
        if (pref[j] == pref[i] - x[cur] && j > before) {
            x[cur - 1] = pref[j] - pref[before];
            cur += 2;
            before = i;
        }
    }
    cout << "Yes\n";
    for (auto val : x) {
        cout << val << ' ';
    }
    cout << '\n';
}