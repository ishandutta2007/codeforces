/*
    18.10.2018 21:04:18
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

vector< int > a;
vector< int > sum;

int xr(int i, int j) {
    return sum[j + 1] ^ sum[i];
}

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (auto& item : a) {
        cin >> item;
    }
    sum.resize(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] ^ a[i];
    }
    // for (auto item : sum) {
    //     cout << item << ' ';
    // }
    // cout << '\n';
    long long ans = 0;
    map< int, long long > m;
    int now = 0;
    int mx = (1 << k) - 1;
    m[0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        if (m[sum[i]] > m[mx - sum[i]]) {
            sum[i] = mx - sum[i];
        }
        ++m[sum[i]];
    }
    // for (auto item : sum) {
    //     cout << item << ' ';
    // }
    // cout << '\n';
    long long nn = n;
    ans = n * (n + 1ll) / 2ll;
    for (auto item : m) {
        ans -= item.second * (item.second - 1ll) / 2ll;
    }
    cout << ans << '\n';
    // 0 1 5 6 1 2 6
    // 0 1 4 3 7 3
    return 0;
}