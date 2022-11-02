#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;

int n;
int a[N], b[N];
int c[N][2];
int m = 0;
void work() {
    cin >> n;
    m = 0;
    for (int i = 1; i <= n; i += 1)
        cin >> a[i], b[i] = a[i], m = max(m, a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i += 1) {
        c[a[i]][i % 2] ++;
        c[b[i]][i % 2] --;
    }

    for (int i = 1; i <= m; i += 1) {
        if (c[i][0] || c[i][1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
        for (int i = 1; i <= m; i += 1)
            c[i][0] = c[i][1] = 0;
    }
}