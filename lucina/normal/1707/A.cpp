#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int n, q;
int a[nax];
char ans[nax];

void solve() {
    cin >> n >> q;


    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int cur = 0;

    for (int i = n ; i >= 1 ; -- i) {
        if (cur < a[i] && cur + 1 <= q) {
            cur += 1;
            ans[i] = '1';
            continue;
        }

        if (cur >= a[i]) {
            ans[i] = '1';
            continue;
        }
        ans[i] = '0';
    }
    ans[n + 1] = '\0';
    cout << ans + 1 << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    long time no, div.1
*/