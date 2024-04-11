#include<bits/stdc++.h>
using namespace std;

int buf[202 * 202];

void solve () {
    int a, b, q;

    cin >> a >> b >> q;

    fill(buf, buf + a * b, 0);

    for (int j = 0 ; j < a * b ; ++ j) {

        buf[j] = j > 0 ? buf[j - 1] : 0;
        int x = j % a % b;
        int y = j % b % a;
        if (x == y) ++ buf[j];
    }

    int res = buf[a * b - 1];


    auto f = [&] (long long x)-> long long {
        long long c = (x / (a * b)) * res;
        c += buf[x % (a * b)];

        return c;
    };

    for (; q -- ; ) {
        long long l, r;
        cin >> l >> r;
        /// how many from 0-> L that has
        cout <<  r - l + 1 - f(r) + f(l - 1) << ' ';
    }

    cout << '\n';
}

int main () {
    int T;

    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ;) {
        solve();
    }
}