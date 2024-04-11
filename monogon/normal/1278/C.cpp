
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
int a[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            a[i] = 2 * a[i] - 3;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += a[i];
            a[i] = cnt;
        }
        cnt = 0;
        map<int, int> m;
        m[0] = n;
        for(int i = 2 * n - 1; i >= n; i--) {
            cnt += a[i];
            m[cnt] = i - n;
        }
        int best = n + m[0];
        for(int i = 0; i < n; i++) {
            if(m.count(-a[i])) {
                best = min(best, (n - i - 1) + m[-a[i]]);
            }
        }
        cout << best << endl;
    }
}