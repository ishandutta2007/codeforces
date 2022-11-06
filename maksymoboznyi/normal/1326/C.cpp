#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 2e5 + 5;
const int M = 998244353;


int n, k, a[N];
int ans = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= n - k + 1)
            ans += a[i], p.pb(i);
    }
    cout << ans << ' ';
    ans = 1;
    for (int i = 0; i + 1 < p.size(); i++) {
        ans *= (p[i + 1] - p[i]);
        ans %= M;
    }
    cout << ans;
    return 0;
}