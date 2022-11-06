#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 4e5 + 5;

int ans, n, x, a[N], pref_kol[N], pref_val[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i], ans = max(ans, a[i]);
    if (x == 1) {
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n + n; i++) {
        pref_kol[i] = pref_kol[i - 1] + a[i];
        pref_val[i] = pref_val[i - 1] + a[i] * (a[i] + 1) / 2;
    }
    if (x == pref_kol[n]) {
        cout << pref_val[n];
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = n + n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (pref_kol[m] - pref_kol[i] < x - 1)
                l = m;
            else
                r = m;
        }
        int val = a[i] + pref_val[l] - pref_val[i];
        int left = x - 1 - (pref_kol[l] - pref_kol[i]);
        val += left * (left + 1) / 2;
        ans = max(ans, val);
    }
    //cout << ans << endl;
    for (int i = 1; i < n + n; i++) {
        if (pref_kol[i] < x)
            continue;
        int l = 1, r = i + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (pref_kol[i] - pref_kol[m - 1] < x)
                r = m;
            else
                l = m;
        }
        int val = pref_val[i] - pref_val[r - 1];
        //cout << val << endl;
        int left = x - (pref_kol[i] - pref_kol[r - 1]);
        val += left * (2 * a[l] - left + 1) / 2;
        //cout << i << ' ' << r << ' ' << left << ' ' << val << ' ' << l << ' ' << a[l] << endl;
        ans = max(ans, val);
    }
    cout << ans;
    return 0;
}