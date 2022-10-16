#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int b[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    if (a[1] != b[1]) return cout << "No" << endl, 0;
    if (a[n] != b[n]) return cout << "No" << endl, 0;
    for (int i = n; i >= 1; --i) a[i] -= a[i-1];
    for (int i = n; i >= 1; --i) b[i] -= b[i-1];
    sort(a + 2, a + n + 1);
    sort(b + 2, b + n + 1);
    for (int i = 2; i <= n; ++i) if (a[i] != b[i]) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}