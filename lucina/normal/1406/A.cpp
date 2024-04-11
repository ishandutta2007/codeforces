#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
int ct[150];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ;  T -- ;) {
        cin >> n;
        memset(ct, 0, sizeof(ct));
        for (int i = 1 ; i <= n ; ++ i) {
            int x;
            cin >> x;
            ct[x] += 1;
        }

        bool ok1 = true, ok2 = true;
        int x = 0, y = 0;

        for (int i = 0 ; i < n ; ++ i) {
            if (ok1 && ct[i]) {
                x += 1;
                ct[i] -= 1;
            } else {
                ok1 = false;
            }
            if (ok2 && ct[i]) {
                y += 1;
                ct[i] -= 1;
            } else ok2 = false;
        }
        cout << x + y << '\n';
    }
}