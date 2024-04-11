#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n, k;
char s[nax];
int a[nax];
array <int, 2> b[nax];

void solve() {
    cin >> n >> k;


    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[i] = {a[i] % k, a[i]};
    }

    sort(b + 1, b + 1 + n);

    int bk = n;
    vector <int> l;

    int64_t ans = 0;
    for (int i = 1 ; i < bk ; ++ i) {
        if (b[i][0] + b[bk][0] >= k) {
            ans += (b[i][1] + b[bk][1]) / k;
            bk -= 1;
        } else {
            l.push_back(b[i][1]);
        }
    }
    if (l.size() % 2) l.push_back(b[bk][1]);

    for (int i = 0 ; i < l.size();  i += 2)
        ans += (l[i] + l[i + 1]) / k;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}