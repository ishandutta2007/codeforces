#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
constexpr int mod = 998244353;
using LL = long long;
int n, p[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0;
        while (n) {
            mx = max(mx, n % 10);
            n /= 10;
        }
        cout << mx << '\n';
    }
}
/*

*/