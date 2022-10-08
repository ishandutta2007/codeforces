
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++) {
            b[i] = a[i % 2 == 0 ? i / 2 : n - i / 2 - 1];
        }
        for(int i = n - 1; i >= 0; i--) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}