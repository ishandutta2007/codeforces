#include <iostream>

using namespace std;

constexpr int N = 100001;

int a[N], n, p;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p, ++a[p];
    int ans = !!a[1];
    for (int gcd = 2; gcd < N; ++gcd) {
        int res = 0;
        for (int p = gcd; p < N; p += gcd)
            res += a[p];
        ans = max(ans, res);
    }
    cout << ans << '\n';
    return 0;
}