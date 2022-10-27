#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];
int64_t b[nax];

bool solve() {
    cin >> n;
    map <int64_t, int> req;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] >>= 1;
        }
        req[a[i]] += 1;
    }

    bool all_ok = true;

    for (int i = 1, x ; i <= n ; ++ i) {
        cin >> x;
        while (x % 2 == 0) x >>= 1;
        bool ok = false;
        while (x > 0) {
            if (req[x] > 0) {
                req[x] -= 1;
                ok = true;
                break;
            }
            x >>= 1;
        }
        if (!ok) all_ok = false;
    }

    return all_ok;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

}