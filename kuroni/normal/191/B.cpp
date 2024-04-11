#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
long long b, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> b; --n;
    // int ans = n; --n;
    long long cur = 0;
    vector<int> ve;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    sort(ve.begin(), ve.end(), greater<int>());
    for (int i = 0; i < k - 1; i++) {
        cur += ve[i];
    }
    for (int i = 1; i <= n; i++) {
        long long tmp = cur;
        if (a[i] >= ve[k - 1]) {
            tmp += ve[k - 1];
        } else {
            tmp += a[i];
        }
        if (tmp > b) {
            return cout << i, 0;
        }
    }
    cout << n + 1;
}