#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int ct[nax];
int h;
mt19937 rng(uint64_t(new char()));
pair <int, int> best[2];

int query(int u, int v, int root) {

    cout << "? " << u << ' ' << v << ' ' << root << endl;
    int foo;
    cin >> foo;
    return foo;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> h;
    const int n = (1 << h) - 1;

    for (int i = 1 ; i <= 420 ; ++ i) {
        static int a[3];
        do {
            for (int j = 0 ; j < 3 ; ++ j) a[j] = rng() % n + 1;
        } while (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]);

        int foo = query(a[0], a[1], a[2]);
        ct[foo] += 1;
    }

    for (int g = 0, bar = -1 ; g < 2 ; ++ g) {

        for (int i = 1 ; i <= n ; ++ i) {
            if (i == bar) continue;
            best[g] = max(best[g], make_pair(ct[i], i));
        }
        if (g == 0) bar = best[g].second;
    }

    int x = best[0].second, y = best[1].second;

    for (int i = 1 ; i <= n ; ++ i) {
        if (i == x || i == y) continue;
        int bar = query(x, y, i);
        if (bar == i) {
            cout << "! " << i << endl;
            return 0;
        }
    }

    throw;
}