#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 3e5 + 5;
const long long M = 1e9 + 7;

long long n, k, pref[N], a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pref[i] = pref[i - 1] + a[i];
    ans = k * pref[n];
    sort(pref + 1, pref + n);
    for (int i = 1; i < k; i++)
        ans -= pref[i];//, cout << pref[i] <<< endl;
    cout << ans;
    return 0;
}