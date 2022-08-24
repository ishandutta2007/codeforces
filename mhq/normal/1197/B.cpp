#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > a(n);
    int where = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) where = i;
    }
    bool ok = true;
    for (int i = 0; i + 1 <= where; i++) {
        if (a[i] > a[i + 1]) ok = false;
    }
    for (int i = where; i + 1 < n; i++) {
        if (a[i] < a[i + 1]) ok = false;
    }
    if (ok) cout << "YES";
    else cout << "NO";
    return 0;
}