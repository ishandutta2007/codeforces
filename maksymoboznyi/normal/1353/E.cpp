#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e6 + 5;

int n, k, a[N], kol[N], kk[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 1e9 + 9;
        for (int i = 0; i < k; i++)
            kol[i] = kk[i] = 0;
        int del = 0, all = 0;
        for (int i = 0; i < s.size(); i++)
            kol[i % k] += (s[i] - '0'), all += (s[i] - '0'), kk[i % k]++;
        if (all == 0) {
            cout << "0\n";
            continue;
        }
        ans = all - 1;
        for (int ost = 0; ost < k; ost++) {
            int tans = all - kol[ost];
            vector<int> q, p;
            q.pb(-1);
            p.pb(0);
            for (int i = ost; i < n; i += k)
                q.pb(s[i] - '0'), p.pb(p.back() + q.back());//, cout << s[i] - '0' << ' ' ;
            //cout << endl;
            set<int> val;
            val.insert(-1);
            for (int i = 2; i < q.size(); i++) {
                ans = min(ans, tans + i + 1 - 2 * p[i] + kol[ost] + (*val.begin()));
                val.insert(2 * p[i - 1] - i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}