#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

int kol[22], f[22];

int get_c(int n, int k) {
    return f[n] / f[k] / f[n - k];
}

signed main()
{
    int t;
    cin >> t;
    f[0] = 1;
    for (int i = 1; i <= 20; i++)
        f[i] = f[i - 1] * i;
    while (t) {
        t--;
        int x;
        cin >> x;
        vector<int> p;
        int mx = 2;
        for (; x > 0; mx++)
            p.pb(x % mx), x /= mx;
        for (int i = 0; i <= 20; i++)
            kol[i] = 0;
        for (int i = 0; i < p.size(); i++)
            kol[p[i]]++;
        int ans = 1, sum = 0;
        for (int i = p.size(); i >= 0; i--)
            if (kol[i] != 0){
                int ost = mx - 1 - (max(i, 1ll) + 1) + 1;
                ost -= sum;
                ans *= get_c(ost, kol[i]);
                //cout << ost << ' ' << kol[i] << ' ' << ans << ' ' << sum << endl;
                sum += kol[i];
            }
        //cout << ans << endl;
        int ans1 = 0;
        sum = 0;
        //cout << mx << ' ' << kol[mx - 2] << endl;
        if (kol[0] != 0 && kol[mx - 2] == 0) {
            ans1 = 1;
            kol[0]--;
            for (int i = p.size() - 1; i >= 0; i--)
                if (kol[i] != 0){
                    int ost = mx - 2 - (max(i, 1ll) + 1) + 1;
                    ost -= sum;
                    if (kol[i] > ost) {
                        ans1 = 0;
                        break;
                    }
                    ans1 *= get_c(ost, kol[i]);
                    sum += kol[i];
                }
            //cout << ans1 << endl;
        }
        cout << ans - ans1 - 1 << "\n";
    }
    return 0;
}