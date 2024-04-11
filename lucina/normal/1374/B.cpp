#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ;) {
        int n;
        cin >> n;
        int op = 0;
        while (n % 6 == 0) {
            n /= 6;
            ++ op;
        }

        int p3 = 0, p2 = 0;
        while (n % 3 == 0) {
            n /= 3;
            ++ p3;
        }

        while (n % 2 == 0) {
            n /= 2;
            ++ p2;
        }


        if (p2 > p3 || n > 1) {
            cout << -1 << '\n';
            continue;
        }

        op += p3 - p2;
        op += p3;
        cout << op << '\n';
    }
}