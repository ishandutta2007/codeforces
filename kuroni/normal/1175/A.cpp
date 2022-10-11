#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, ans = -1;
        cin >> n >> k;
        while (n != 0)
        {
            ans += n % k + 1;
            n /= k;
        }
        cout << ans << '\n';
    }
}