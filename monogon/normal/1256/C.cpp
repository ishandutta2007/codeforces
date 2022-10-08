
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n, m, d;
int c[N], a[N], ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    a[0] = d;
    for(int i = 0; i < m; i++) {
        cin >> c[i];
        if(i > 0)
            a[i] = a[i - 1] + c[i - 1] + d - 1;
    }
    a[m] = n + 1;
    for(int i = m - 1; i >= 0; i--) {
        if(a[i] + c[i] > a[i + 1]) {
            a[i] = a[i + 1] - c[i];
        }
    }
    if(a[m] - a[m - 1] - c[m - 1] + 1 > d) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < m; i++) {
        fill(ans + a[i], ans + a[i] + c[i], i + 1);
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}