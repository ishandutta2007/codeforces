#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int max_can = 0;
    for (int i = 0; i < n; i++) {
        max_can += i / 2;
    }
    if (m > max_can) {
        cout << "-1\n";
        return 0;
    }

    vector<int> a;
    while (len(a) / 2 < m) {
        m -= len(a) / 2;
        a.push_back(len(a) + 1);
    }
    if (m) {
        int first = 0;
        while ((len(a) - first) / 2 > m) first++;
        a.push_back(a[first] + a.back());
    }
    
    int big = a.empty() ? n + 1 : a.back() + 1;
    assert(len(a) <= n);
    while (len(a) != n) {
        a.push_back(int(1e7) + big * len(a));
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}