/*
    17.11.2018 0:32:19
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            a[i + 1] = 0;
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}