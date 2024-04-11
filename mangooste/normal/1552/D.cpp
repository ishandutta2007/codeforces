#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x = abs(x);
    }
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());

    if (len(a) < n) {
        cout << "YES\n";
        return;
    }

    vector<int> p3(n + 1, 1);
    for (int i = 1; i <= n; i++)
        p3[i] = p3[i - 1] * 3;

    auto get = [&](int mask, int pos) {
        return mask / p3[pos] % 3;
    };

    for (int mask = 1; mask < p3[n]; mask++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int coeff = get(mask, j);
            if (coeff == 2)
                coeff = -1;

            sum += a[j] * coeff;
        }

        if (sum == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}