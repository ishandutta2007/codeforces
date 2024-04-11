#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 3e5 + 5;

int t, n;
string a, b;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        vector<int> ans;
        char s = a[0];
        int l = 0, r = n - 1, kol = 0;
        for (int i = n - 1; i >= 0; i--) {
            char c;
            if (l <= r)
                c = a[l + i];
            else
                c = a[l - i];
            //cout << i << ' ' << c << ' ' << l << ' ' <<  r << endl;
            if (kol % 2)
                if (c == '1')
                    c = '0';
                else
                    c = '1';
            if (c == b[i])
                continue;
            if (s != b[i]) {
                int nl, nr;
                if (l <= r)
                    nl = l + i, nr = l;
                else
                    nl = l - i, nr = l;
                l = nl;
                r = nr;
                if (c == '1')
                    s = '0';
                else
                    s = '1';
                kol++;
                ans.pb(i);
            } else {
                ans.pb(0);
                    int nl, nr;
                if (l <= r)
                    nl = l + i, nr = l;
                else
                    nl = l - i, nr = l;
                l = nl;
                r = nr;
                if (c == '1')
                    s = '0';
                else
                    s = '1';
                kol++;
                ans.pb(i);

            }
        }
        cout << ans.size() << "\n";
        for (auto x: ans)
            cout << x + 1 << ' ';
        cout << "\n";
    }
    return 0;
}