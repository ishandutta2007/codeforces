#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int a[nax];
int ans[nax];

void solve() {
    cin >> n;
    int64_t s = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        s += a[i];
    }
    int c = s / n;
    deque <int> zeros;
    for (int i = n ; i >= 1 ; -- i) {
        if (c == 0) {
            ans[i] = 0;
            continue;
        }
        int g1 = (i - 1);
        int res_c = c;
        if (res_c > zeros.size()) {
            g1 += n - i + 1;
        } else {
            g1 += zeros[res_c - 1] - i;
        }
        if (g1 == a[i]) {
            ans[i] = 1;
            c -= 1;
        } else {
            ans[i] = 0;
            zeros.push_front(i);
        }
        /**
        Let's say this position is 1
        .....1.....
        we know exactly, there exists V 1's on the left
        and if 0
        it's the first position in which things turn out
        but of course, it's differ by at least 1
        */
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }

}