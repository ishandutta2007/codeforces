#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

void solve() {
    int l, r;
    long long m;
    cin >> l >> r >> m;

    for (int a = l ; a <= r ; ++ a) {
        int md = m % a;
        int need = (a - md) % a;
        /**
        c - b = md
        */
        if (r - md >= l && m - md > 0) {
            cout << a << ' ' << r << ' ' << r - md << '\n';
            return ;
        }

        if (r - need >= l) {
            cout << a << ' ' << r - need << ' ' << r << '\n';
            return;
        }
    }

    assert(false);
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    not ryza again.
*/