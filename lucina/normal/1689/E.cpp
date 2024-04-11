#include<bits/stdc++.h>
using namespace std;
const int nax = 4096;
int n;
int a[nax];
int b[nax];
int par[nax];

int find_par(int x) {
    return x == par[x] ? x : par[x] = find_par(par[x]);
}

bool unite(int x, int y) {
    x = find_par(x), y = find_par(y);
    if (x == y) return false;
    par[x] = y;
    return true;
}


void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[i] = a[i];
        if (a[i] == 0) {
            a[i] += 1;
        }
    }


    auto check = [&]()-> bool {
        iota(par + 1, par + 1 + n, 1);
        for (int j = 0 ; j <= 30 ; ++ j)
        for (int i = 1, foo = -1 ; i <= n ; ++ i) {
            if (a[i] >> j & 1) {
                if (foo != -1) unite(i, foo);
                else foo = i;
            }
        }
        for (int i = 1 ; i <= n ; ++ i) {
            if (find_par(i) != find_par(1)) return false;
        }
        return true;
    };
    auto print_ans = [&]() {
        int s = 0;
        for (int i = 1 ; i <= n ; ++ i) {
            s += abs(a[i] - b[i]);
        }
        cout << s << '\n';
        for (int i = 1 ; i <= n ; ++ i)
            cout << a[i] << ' ';
        cout << '\n';
    };

    if (check()) return print_ans();

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] > 1) {
            a[i] -= 1;
            if (check()) {
                return print_ans();
            }
            a[i] += 1;
        }
    }


    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] > 1) {
            a[i] += 1;
            if (check()) {
                return print_ans();
            }
            a[i] -= 1;
        }
    }

    int mx_bit = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if ((a[i] & -a[i]) > mx_bit) mx_bit = (a[i] & -a[i]);
    }
    vector <int> bar;
    for (int i = 1 ; i <= n ; ++ i) {
        if ((a[i] & -a[i]) == mx_bit) bar.push_back(i);
    }
    assert(bar.size() >= 2);
    a[bar[0]] -= 1, a[bar[1]] += 1;
    assert(check());
    print_ans();
}

 main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    +_+ So bored lately.
*/