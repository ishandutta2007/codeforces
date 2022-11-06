#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;

long long n, s[N], pref[N];
long long ans = 0;
vector<int> stop;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s + 1, s + n + 1);
    stop.pb(1000000000000000002);
    for (int i = 2; i <= n; i++)
        stop.pb(s[i] - s[i - 1]);
    sort(stop.begin(), stop.end());
    pref[0] = stop[0];
    for (int i = 1; i < stop.size(); i++)
        pref[i] = stop[i] + pref[i - 1];
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        unsigned long long len = r - l;
        int pos = upper_bound(stop.begin(), stop.end(), len) - stop.begin() - 1;
        pos++;
        int sum = pref[pos];
        sum -= stop[pos];
        unsigned long long ans = (len + 1) * (n - pos) + sum;
        cout << ans << ' ';
    }
    return 0;
}