/*
    20.12.2018 15:36:46
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector< int > a(n);
    map< int, int > mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = n - a[i];
        ++mp[a[i]];
    }
    for (auto& item : mp) {
        if (item.second % item.first != 0) {
            cout << "Impossible\n";
            return 0;
        }
    }
    int ind = 1;
    vector< int > col(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (mp[a[i]] % a[i] == 0) {
            col[a[i]] = ind;
            ++ind;
        }
        --mp[a[i]];
        a[i] = col[a[i]];
    }
    cout << "Possible\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}