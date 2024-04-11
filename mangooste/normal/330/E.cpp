#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline pr<int> mp(int a, int b) {
    if (a > b)
        swap(a, b);
    return {a, b};
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    set<pr<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.insert(mp(a, b));
    }
    vec<int> ord(n);
    iota(all(ord), 1);
    while (double(clock()) / CLOCKS_PER_SEC < 1.3) {
        shuffle(all(ord), rng);
        bool ok = true;
        for (int i = 0; i < m && ok; i++)
            ok &= !edges.count(mp(ord[i], ord[(i + 1) % n]));
        if (ok) {
            for (int i = 0; i < m; i++)
                cout << ord[i] << ' ' << ord[(i + 1) % n] << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}