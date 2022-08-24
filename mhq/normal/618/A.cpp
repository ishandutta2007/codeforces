#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
    vector < int > v;
    for (int i = 1; i <= n; i++) {
        v.push_back(1);
        while (v.size() >= 2 && v[v.size() - 2] == v.back()) {
            v.pop_back();
            v.back()++;
        }
    }
    for (int u : v) cout << u << " ";
    return 0;
}