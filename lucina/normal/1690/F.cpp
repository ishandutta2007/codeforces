#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n, k;
char s[nax];
int p[nax];
bool vis[nax];

int64_t my_lcm2(int64_t a, int64_t b) {
    using ll = __int128;
    return ll(a) * ll(b) / ll(gcd(a, b));
}

template <typename T>
int64_t my_lcm(vector <T> x) {
    int64_t res = 1;
    for (int i = 0 ; i < x.size() ; ++ i) res = my_lcm2(x[i], res);
    return res;
}

string cyclic_shift(string v) {
    char x = v.back();
    v.pop_back();
    v = x + v;
    return v;
}

string cyclic_shift(string v, int l) {
    string res = v;
    for (int i = 0 ; i < v.size() ; ++ i) {
        res[(i + l) % res.size()] = v[i];
    }
    return res;
}

void solve() {
    cin >> n >> s + 1;
    fill(vis + 1, vis + 1 + n, false);

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> p[i];
    }

    vector <int64_t> all;

    for (int i = 1 ; i <= n ; ++ i) {
        if (vis[i]) continue;
        int x = i;
        string cyc;
        do {
            vis[x] = true;
            cyc += s[x];
            x = p[x];
        } while (x != i);

        int m = cyc.size();
        int ans = 0;
        for (int i = 1 ; i <= m ; ++ i) {
            if (m % i) continue;
            if (cyclic_shift(cyc, i) == cyc) {
                ans = i;
                break;
            }
        }
        all.push_back(ans);
    }
    cout << my_lcm(all) << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}