#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n > m) {
            cout << "NO\n";
            continue;
        }
        else {
            if (n % 2 == 1) {
                cout << "YES\n";
                for(int i = 0; i < n - 1; i++) {
                    cout << 1 << " ";
                }
                cout << m - n + 1 << endl;
            }
            else {
                if (m % 2 == 1) {
                    cout << "NO\n";
                }
                else {
                    cout << "YES\n";
                    for(int i = 0; i < n - 2; i++) {
                        cout << 1 << " ";
                    }
                    cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << endl;
                }
            }
        }
    }
    return 0;
}