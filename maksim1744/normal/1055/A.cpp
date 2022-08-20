/*
    12.11.2018 21:38:50
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, s;
    cin >> n >> s;
    --s;
    vector< int > a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (a[0] == 0) {
        cout << "NO\n";
        return 0;
    }
    if (a[s] == 1) {
        cout << "YES\n";
        return 0;
    }
    if (b[s] == 0) {
        cout << "NO\n";
        return 0;
    }
    bool ok = false;
    for (int i = s + 1; i < n; ++i) {
        if (a[i] == 1 && b[i] == 1) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << "YES\n";
        return 0;
    } else {
        cout << "NO\n";
        return 0;
    }
    return 0;
}