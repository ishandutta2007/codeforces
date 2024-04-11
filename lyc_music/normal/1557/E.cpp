#include <bits/stdc++.h>

#define MultiTest
//#define Precision

using namespace std;


void solve() {
    int n = 8;
    string resp;
    while (true) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << i << " " << (i % 2 ? j : 9 - j) << endl;
                cin >> resp;
                if (resp == "Done") return;
            }
        }
    }
}


int main() {
//    ios::sync_with_stdio(false);
    int t = 1;
#ifdef MultiTest
    cin >> t;
#endif
#ifdef Precision
    cout << fixed << setprecision(9);
#endif
    while (t--) {
        solve();
    }
    return 0;
}