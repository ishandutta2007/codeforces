#include <bits/stdc++.h>

using namespace std;

long long n;

long long cal(long long x) {
    return n / x + (n / x) * (n / x - 1) / 2 * x;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    set <long long> ans;
    for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
        ans.insert(cal(i));
        ans.insert(cal(n / i));
    }
    for (auto x: ans) cout << x << ' '; cout << endl;
    return 0;
}