#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], b[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = n / 2 * (n / 2 + 1) / 2;
        int sum = ans;
        for (int i = 2; i <= n / 2; i++)
            sum += i - 1, ans += sum;
        ans *= 4;
        //cout << ans << endl;
        ans += 4 * (n / 2) * (n / 2 + 1) / 2;
        cout << ans << "\n";
    }
    return 0;
}