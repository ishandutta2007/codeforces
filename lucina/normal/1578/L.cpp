#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, a[nax];
int h;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cin >> n >> h;
        for (int i = 1 ; i <= n ; ++ i)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        int x = a[n], y = a[n - 1];
        int ans = (h / (x + y));
        h -= 1LL * (x + y) * ans;
        ans *= 2;
        if (h > 0) ans ++, h -= x;
        if (h > 0) ans ++, h -= y;
        cout << ans << '\n';
    }
}
/*
    Well, such a long time from last div.2 round.
*/