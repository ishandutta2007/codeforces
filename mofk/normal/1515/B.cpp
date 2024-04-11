#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    set<int> v;
    const int inf = 1e9;
    for (int i = 1; 2 * i * i <= inf; ++i) v.insert(2 * i * i);
    for (int i = 1; 4 * i * i <= inf; ++i) v.insert(4 * i * i);
    while (ntest--) {
        int n;
        cin >> n;
        if (v.find(n) == v.end()) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}