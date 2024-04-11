/*
    17.11.2018 0:24:43
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > a(n);
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    long long mx = *max_element(a.begin(), a.end());
    vector< int > ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) {
            if (mx * 2 < sm - mx) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (i != j && a[j] * 2 == sm - mx) {
                    ans.push_back(i + 1);
                    break;
                }
            }
        } else {
            if (sm - a[i] == 2 * mx) {
                ans.push_back(i + 1);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto item : ans) {
        cout << item << ' ';
    }
    cout << '\n';
    return 0;
}