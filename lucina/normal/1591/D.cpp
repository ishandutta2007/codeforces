#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

int f[nax];

void add(int x, int y) {
    for (; x < nax ; x += x & -x)
        f[x] += y;
}
int get(int x) {
    int res = 0;
    for (; x > 0 ; x -= x & -x)
        res += f[x];
    return res;
}
void c(int * a, int x, int y, int z) {
    int u = a[x], v = a[y], w = a[z];
    a[x] = w, a[y] = u, a[z] = v;
}
tuple <int, int, int> get_rand(int n) {
    while (true) {
        int u = rand() % n;
        int v = rand() % n;
        int w = rand() % n;
        if (u == v || u == w || v == w) continue;
        return make_tuple(u, v, w);
    }
    throw;
    assert(false);
}
void show_rand_permu(int n) {
    int ff[n + 2];
    for (int i = 0 ; i < n ; ++ i)
        ff[i] = rand()%n + 1;
    for (int x = 0 ; x < n ; ++ x) {
        auto [u, v, w] = get_rand(n);
        c(ff, u, v, w);
    }
    for (int i = 0 ; i < n ; ++ i) {
        cout << ff[i] << ' ';
    }
    int64_t sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        sum += get(n) - get(ff[i]);
        //sum %= 2;
        add(ff[i], 1);
    }
    for (int i = 0 ; i < n ; ++ i)
        add(ff[i], -1);
    cout << "S " << sum << '\n';
    assert(sum % 2 == 0);
    cout << '\n';
}
void solve() {
    set <int> d;
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i], d.insert(a[i]);
    int64_t sum = 0;
    if (d.size() != n) {
        cout << "YES\n";
        return;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        sum += get(n) - get(a[i]);
        sum %= 2;
        add(a[i], 1);
    }
    for (int i = 1 ; i <= n ; ++ i)
        add(a[i], -1);
    cout << (sum % 2 ? "NO" : "YES") << '\n';
}

int main() {
    srand(uint64_t(new char()));
    cin.tie(0)->sync_with_stdio(false);
    int T;
//    for (int i = 0 ; i < 1000 ; ++ i)
//        show_rand_permu(4);
    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/**
    Final exam tomorrow?
    Who cared.
*/