#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int g = a[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, a[i]);
    int m = *max_element(all(a));
    vector<int> start(m + 2, 0), cnt(m + 2, 0);
    for (int i : a)
        start[i / g]++;
    vector<char> used(m + 2, 0);
    for (int i = 2; i <= m; i++) {
        if (used[i])
            continue;
        for (int j = i; j <= m; j += i)
            cnt[i] += start[j], used[j] = 1;
    }
    int mx = *max_element(all(cnt));
    cout << (mx == 0 ? -1 : n - mx) << '\n';
}