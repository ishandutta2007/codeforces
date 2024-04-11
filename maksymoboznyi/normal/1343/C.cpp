#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 1;
const int M = 998244353;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> p;
        int cur = a[1];
        for (int i = 2; i <= n; i++) {
            if (a[i] < 0)
                if (a[i - 1] < 0)
                    cur = max(cur, a[i]);
                else
                    p.pb(cur), cur = a[i];
            else
                if (a[i - 1] < 0)
                    p.pb(cur), cur = a[i];
                else
                    cur = max(cur, a[i]);
        }
        p.pb(cur);

        //cout << p.size() << endl;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < p.size(); i++)
            s1 += p[i];//, cout << p[i] << ' ';
        cout << s1 << "\n";
    }
    return 0;
}