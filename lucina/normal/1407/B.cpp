#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ;  T -- ;) {
        cin >> n;
        for (int i = 1 ; i <= n ; ++ i)
            cin >> a[i];
        static bool used[nax];
        fill(used, used + n + 1, false);
        sort(a + 1, a + 1 + n, greater <int>());


        int cur_gcd = 0;

        while (accumulate(used + 1, used + 1 + n, 0) != n) {
            if (cur_gcd == 0) {
                cur_gcd = a[1];
            }

            int mx = -1;

            for (int i = 1 ; i <= n ; ++ i) {
                if (used[i]) continue;
                if (gcd(cur_gcd, a[i]) > mx) {
                    mx = gcd(cur_gcd, a[i]);
                }
            }
            cur_gcd = mx;

            for (int i = 1 ; i <= n ; ++ i) {
                if (used[i]) continue;
                if (gcd(cur_gcd, a[i]) == cur_gcd) {
                    cout << a[i] << ' ';
                    used[i] = true;
                }
            }
        }
        cout << '\n';
    }
}
/**
    Why 9am tomorrow?
    :sad face
*/