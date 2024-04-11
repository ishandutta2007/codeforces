#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e6 + 5;

int n, m, s, used[N];

signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int kol = 60, l = -1, r = 1e9;///TTRWGZHTRJTHERGFGRSHZTEW
    while (l < r - 1) {
        int m = (l + r) / 2;
        kol--;
        cout << "> " << m << endl;
        int ans;
        cin >> ans;
        if (ans == 0)
            r = m;
        else
            l = m;
    }
    m = r;
    int k = n;
    int ans = 0, it = 0;
    vector<int> vv;
    for (int i = 1; i <= n; i++)
        vv.pb(i);
    int mm = m;
    random_shuffle(vv.begin(), vv.end());
    for (int i = 0; i < min(kol, 1ll*vv.size()); i++)
    {
        cout << "? " << vv[i] << endl;
        int x;
        cin >> x;
        mm = min(mm, x);
        ans = __gcd(ans, m - x);
    }
    vector<int> d;
    for (int i = 1; i * i <= ans; i++)
        if (ans % i == 0)
            d.pb(i), d.pb(ans / i);
    ans = 1000000000;
    for (int i = 0; i < d.size(); i++)
        if (m - d[i] * (n - 1) <= mm)
            ans =  min(ans, d[i]);
    cout << "! " << m - ans * (n-1) << ' ' << ans << endl;
    return 0;
}