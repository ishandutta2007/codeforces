#include <bits/stdc++.h>

using namespace std;

int n;
int b[200005];
long long a[200005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    long long mx = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = mx + b[i];
        cout << a[i] << ' ';
        mx = max(mx, a[i]);
    }
    cout << endl;
    return 0;
}