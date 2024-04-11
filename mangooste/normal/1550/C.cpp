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
    for (auto &x : a)
        cin >> x;

    int answer = 0;
    for (int i = 0; i < n; i++) {
        vector<int> current{a[i]};
        current.reserve(4);

        auto good = [&]() {
            for (int i = 0; i < len(current); i++)
                for (int j = i + 1; j < len(current); j++)
                    for (int k = j + 1; k < len(current); k++)
                        if (min(current[i], current[k]) <= current[j] && current[j] <= max(current[i], current[k]))
                            return false;

            return true;
        };

        int j = i + 1;
        while (j < n && good())
            current.push_back(a[j++]);

        if (!good())
            current.pop_back();

        assert(good());
        answer += len(current);
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}