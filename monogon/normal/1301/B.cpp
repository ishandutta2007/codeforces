
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int m = 1e9, M = -1e9;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            if(a[i] != -1 && ((i > 0 && a[i - 1] == -1) || (i < n - 1 && a[i + 1] == -1))) {
                m = min(m, a[i]);
                M = max(M, a[i]);
            }
        }
        int k = m + (M - m) / 2;
        for(int i = 0; i < n; i++) {
            if(a[i] == -1) {
                a[i] = k;
            }
        }
        int dif = 0;
        for(int i = 1; i < n; i++) {
            dif = max(dif, abs(a[i] - a[i - 1]));
        }
        cout << dif << " " << k << endl;
    }
}