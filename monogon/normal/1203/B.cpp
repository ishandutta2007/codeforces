
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 105;
int q, n;
int a[4 * MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 0; i < 4 * n; i++) {
            cin >> a[i];
        }
        sort(a, a + 4 * n);
        ll A;
        for(int i = 0; i < 4 * n; i += 2) {
            if(a[i] != a[i + 1]) {
                cout << "NO" << endl;
                goto endloop;
            }
        }
        A = ((ll) a[0]) * ((ll) a[4 * n - 1]);
        for(int i = 0; i < 4 * n; i++) {
            if(((ll) a[i]) * ((ll) a[4 * n - i - 1]) != A) {
                cout << "NO" << endl;
                goto endloop;
            }
        }
        cout << "YES" << endl;
        endloop:;
    }
}