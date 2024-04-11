/*
    18.10.2018 19:42:00
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > a(n);
    for (auto& item : a) {
        cin >> item;
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > mx) {
            cout << i + 1 << '\n';
            return 0;
        }
        mx = max(mx, a[i] + 1);
    }
    cout << -1 << '\n';
    return 0;
}