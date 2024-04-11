#include <bits/stdc++.h>

using namespace std;

int n, s;
int a[1006], b[1006];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    if (!a[1]) return cout << "NO" << endl, 0;
    if (a[s]) return cout << "YES" << endl, 0;
    if (!b[s]) return cout << "NO" << endl, 0;
    for (int i = s + 1; i <= n; ++i) if (a[i] && b[i]) return cout << "YES" << endl, 0;
    cout << "NO" << endl;
    return 0;
}