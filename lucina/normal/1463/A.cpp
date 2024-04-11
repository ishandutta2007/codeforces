#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T; T -- ; ) {
        static int a[5];
        for (int i = 0 ; i < 3 ; ++ i)
            cin >> a[i];
        sort(a, a + 3);
        int sum = a[0] + a[1] + a[2];
        bool ok = true;

        if (sum % 9) ok = false;
        if (a[0] < sum / 9) ok = false;
        cout << (ok ? "YES" : "NO") << '\n';
    }
}