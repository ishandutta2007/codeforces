#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
int pos[nax];
bool vis[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        pos[a[i]] = i;
        vis[i] = false;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
    }

    int sz = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (vis[i]) continue;
        int x = i;
        vis[x] = true;
        int c = 0;
        do {
            c += 1;
            x = pos[b[x]];
            vis[x] = true;
        } while (x != i);
        sz += c / 2;
    }

    int64_t ans = 0;
    for (int j = 0 ; j < sz ; ++ j) {
        ans += n - j;
        ans -= j + 1;
    }


    cout << ans * 2 << '\n';

    /**
        the maximum sum is 2 * max - 2 * min
    */

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Long time, div.1 round :)
*/