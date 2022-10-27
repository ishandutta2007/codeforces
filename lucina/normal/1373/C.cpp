#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;

char s[nax];

void solve () {
    cin >> s + 1;
    int n = strlen(s + 1);

    int bal = 0;
    map <int, int> keep;

    for (int i = 1 ; i <= n ; ++ i) {
        bal += (s[i] == '+' ? 1 : -1);
        if (bal < 0) {
            if (!keep.count(bal)) {
                keep[bal] = i;
            }
        }
    }

    long long ans = 0;

    for (auto &p : keep) {
        ans += p.second;
    }

    ans += n;
    cout << ans << '\n';
}

int main () {
    int T;

    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Sue is best girl in A19.
*/