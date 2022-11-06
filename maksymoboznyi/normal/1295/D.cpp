#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 1e18;

int nxt[N][30], lst[30];

int kol(int l, int r, int k) {
    int res = r / k + 1;
    if (l != 0)
        res -= ((l-1) / k + 1);
    return res;
}

signed main()
{/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/

    int T;
    cin >> T;
    while (T > 0) {
        T--;
        int a, m, g, km;
        cin >> a >> m;
        g = __gcd(a, m);
        km = m;
        m /= g;
        vector<int> d;
        for (int i = 1; i * i <= m; i++)
            if (m % i == 0)
                if (i * i == m)
                    d.pb(i);
                else
                    d.pb(m / i), d.pb(i);
        d.pb(m);
        vector<int> c;
        int p = 2, mm = m;
        while (p * p <= mm) {
            if (m % p == 0) {
                c.pb(p);
                while (m % p == 0)
                    m /= p;
            }
            p++;
        }
        if (m != 1)
            c.pb(m);
        sort(d.begin(), d.end());
        vector<int> val, di;
        val.pb(0);
        for (int i = 1; i < d.size(); i++) {
            int x = d[i];
            val.pb(0);
           // di.pb(0);
            for (int j = 0; j < c.size(); j++)
                if (x % c[j] == 0) {
                    val.back()++;
                    //cout << '*' << x << ' ' << c[j] << endl;
                    int k1 = 0;
                    while (x % c[j] == 0)
                        x /= c[j], k1++;
                    if (k1 > 1) {
                        val.back() = -1;
                        break;
                    }
                }
        }
        int ans = 0;
        ans += kol(a, a + km - 1, g);
       // cout << g << ' ' << ans << endl;
        for (int i = 1; i < d.size(); i++)
            if (d[i] != d[i - 1] && val[i] != -1) {
                int res = kol(a, a + km - 1, g * d[i]);
                if (val[i] % 2 == 0)
                    ans += res;
                else
                    ans -= res;
                //cout << val[i] << ' ' << d[i] << ' ' << ans << endl;
            }
        /*int an2 = 0;
        for (int i = 0; i < km; i++)
            if (__gcd(i + a, km) == __gcd(a, km))
                an2++;
        cout << an2 << "\n";
        */cout << ans << "\n";
    }
    return 0;
}