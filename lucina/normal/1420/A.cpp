#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T --  ;) {
        cin >> n;
        for (int i = 1 ; i <= n; ++ i)
            cin >> a[i];
        bool f = is_sorted(a + 1, a + 1 + n, greater<int>());
        if (!f) {
            cout << "YES\n";
        } else {
            sort(a + 1, a + 1 + n);
            int m = unique(a + 1, a + 1 + n) - a - 1;
            if (m != n) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}