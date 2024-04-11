#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

bool solve() {
    cin >> n;
    int cnt[2]{};
    for (int i = 1 ; i <= n ; ++ i) {
        int x; cin >> x;
        cnt[abs(x) % 2] += 1;
    }

    if (cnt[1] % 2 == 0) {
        return cnt[1] % 4 == 0;
    }
    bool win = (((cnt[1] + 1) / 2) % 2 == 0);
    if (win) return true;
    return cnt[0] % 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "Alice" : "Bob") << '\n';
    }
}