#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    while (n > 0) {
        if (n % k == 0) {
            ans += 1;
            n /= k;
        } else {
            ans += n % k;
            n -= n % k;
        }
    }
    cout << ans << "\n";
    }
    return 0;
}