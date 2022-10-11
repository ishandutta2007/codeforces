#include <bits/stdc++.h>
using namespace std;

const int MX = 32000;

int t, n, chk[MX];
vector<int> pr;

bool is_prime(int u) {
    for (int &v : pr) {
        if (v < u && u % v == 0) {
            return false;
        } else if (v >= u) {
            break;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < MX; i++) {
        if (!chk[i]) {
            pr.push_back(i);
            for (int j = i * i; j < MX; j += i) {
                chk[j] = true;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        int u, v;
        for (int i = n; ; i--) {
            if (is_prime(i)) {
                u = i;
                break;
            }
        }
        for (int i = n + 1; ; i++) {
            if (is_prime(i)) {
                v = i;
                break;
            }
        }
        long long p = 1LL * u * v - 2 * v + 2 * n - 2 * u + 2;
        long long q = 2LL * u * v;
        cout << p / __gcd(p, q) << "/" << q / __gcd(p, q) << '\n';
    }
}