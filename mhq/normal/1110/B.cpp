#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;
typedef long long ll;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int n, m, k;
const int maxN = (int)1e5 + 100;
int b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < int > all;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i + 1 <= n; i++) {
        all.push_back(b[i + 1] - b[i] - 1);
    }
    ll total_len = b[n] - b[1] + 1;
    sort(all.begin(), all.end());
    for (int i = 1; i <= k - 1; i++) {
        total_len -= all.back();
        all.pop_back();
    }
    cout << total_len;
    return 0;
}