#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;


int main() {


    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    for (int _ = 1 ; _ <= T ; ++ _) {
        int n;
        static int a[256];
        cin >> n;
        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
        }
        for (int i = 2 ; i < n ; ++ i) {
            if (a[i] != a[i - 1]) {
                cout << ((a[i] == a[i + 1]) ? i - 1 : i) << '\n';
                goto BAR;
            }
        }
        cout << (a[1] == a[2] ? n : 1) << '\n';
        BAR:;
    }

}