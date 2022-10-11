#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

    int n;
    cin >> n;
    vec<int> deg(n);
    for (auto &x : deg) {
        cin >> x;
    }
    vec<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            all.emplace_back(i, j);
        }
    }
    sort(all(all), [&](pair<int, int> a, pair<int, int> b) {
        return abs(deg[a.first] - deg[a.second]) > abs(deg[b.first] - deg[b.second]);
    });
    auto query = [&](int a, int b) {
        cout << "? " << a + 1 << ' ' << b + 1 << endl;
        string res;
        cin >> res;
        return res == "Yes";
    };
    for (auto [v, u] : all) {
        if (deg[v] < deg[u]) {
            swap(v, u);
        }
        if (query(v, u)) {
            cout << "! " << v + 1 << ' ' << u + 1 << '\n';
            return 0;
        }
    }
    cout << "! 0 0\n";
}