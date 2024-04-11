
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// probability that value V appears K times?
// ((m choose K) * (n choose K) * K! * (mn - n choose m - K) * (m - K)!) / (mn)!

// (mn choose n) total possibilities
// (m choose K) * (mn - m choose n - k) other possibilities

// m!          (mn - m) !                 n! (mn - n)!
// k! (m - k)! (n - k)! (mn - m - n + k)! (mn)!

// (m choose K)

// P(V is selected | V appears K times) = K/n

// n * sum_{K=1^n} P(V appears K times) * (K / n)^2

const int N = 1e3 + 5;
int n, m;

long double choose(int n, int k) {
    long double ans = 1;
    for(int i = 1; i <= k; i++) {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    long double ans = 0;
    for(int k = 1; k <= min({n, m}); k++) {
        ans += k * k * choose(m, k) * choose(m * n - m, n - k) / choose(m * n, n);
    }
    cout << fixed << setprecision(8);
    cout << (ans / n) << '\n';
}