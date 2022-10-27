#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        int n;
        static int a[nax];

        cin >> n;

        bool same = true;

        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
            same &= a[i] == a[1];
        }

        if (same) {
            cout << -1 << '\n';
        } else {
            int foo = *max_element(a + 1, a + 1 + n);

            for (int i = 1 ; i <= n ; ++ i) {
                if (a[i] != foo) continue;
                if (
                    (i > 1 && (a[i - 1] != a[i]))
                    || (i < n && (a[i + 1] != a[i])))
                    {
                        cout << i << '\n';
                        break;
                    }
            }

        }
    }

}