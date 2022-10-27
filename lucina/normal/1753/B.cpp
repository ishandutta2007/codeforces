#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;
int n;
int cnt[nax];
int x;

void solve() {
    cin >> n >> x;

    for (int i = 1 ; i <= n ; ++ i) {
        int a;
        cin >> a;
        cnt[a] += 1;
    }

    for (int i = 1 ; i < x ; ++ i) {
        cnt[i + 1] += cnt[i] / (i + 1);
        if (cnt[i] % (i + 1)) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (T = 1 ; T -- ;) {
        solve();
    }
}
/*
    div1
*/