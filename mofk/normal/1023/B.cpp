#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long r = min(n, (k - 1) / 2);
    long long l = max(1LL, k - n);
    cout << max(0LL, r - l + 1) << endl;
    return 0;
}