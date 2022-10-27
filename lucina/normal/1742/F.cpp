#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int q;

void solve() {
    cin >> q;

    char mx_1 = 'a', mx = 'a';
    int64_t l[3]{};
    l[1] = l[2] = 1;


    for (int i = 1 ; i <= q ; ++ i) {
        int t, k; string x;
        cin >> t >> k >> x;

        if (t == 2) {
            for (char c : x)
                mx = max(mx, c);
        }
        if (t == 1) {
            for (char c : x)
                mx_1 = max(mx_1, c);
        }
        l[t] += 1ll * k * x.size();

        if ('a' < mx) {
            cout << "YES\n";
            continue;
        }
        if (mx_1 != 'a') {
            cout << "NO\n";
            continue;
        }

        cout << (l[1] < l[2] ? "YES" : "NO") << '\n';



    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}