/**
 * @author Macesuted (macesuted@qq.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pii;

#define maxn 10005

set<int> S;

void f(int n, int m, int a, int b) {
    for (register int i = 0; i <= a; i++) {
        int j = a - i;
        if (i > n || j > m) continue;
        int ans = n - i + j;
        S.insert(ans);
    }
    return;
}

void work(void) {
    S.clear();
    int n, m;
    cin >> n >> m;
    int b = (n + m) / 2, a = n + m - b;
    f(a, b, n, m), f(b, a, n, m);
    cout << S.size() << endl;
    for (set<int>::iterator i = S.begin(); i != S.end(); i++) cout << *i << ' ';
    cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--) work();
    return 0;
}