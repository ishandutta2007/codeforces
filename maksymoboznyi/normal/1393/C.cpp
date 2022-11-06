#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, a[N], kol[N], k1[N];

bool check(int d) {
    set<pair<int, int> > can;
    for (int i = 1; i <= n; i++) {
        k1[i] = kol[i];
        if (k1[i] != 0)
            can.insert({k1[i], i});
    }
    vector<int> q;
    for (int i = 0; i < n; i++) {
        //cout << i << ' ' << can.size() << endl;
        if (i <= d) {
            auto it = can.end();
            if (can.size() == 0)
                return 0;
            it--;
            //cout << it -> second << endl;
            int x = it -> second;
            //cout << x << endl;
            can.erase(it);
            q.pb(x);
            k1[x]--;
        } else {
            if (k1[q[i - d - 1]] != 0)
                can.insert({k1[q[i - d - 1]], q[i - d - 1]});
            if (can.size() == 0)
                return 0;
            auto it = can.end();
            it--;
            int x = it -> second;
            //cout << x << endl;
            can.erase(it);
            q.pb(x);
            k1[x]--;
        }
    }
    return 1;
}

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
        kol[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        kol[a[i]]++;
    }
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l << "\n";
    }
    return 0;
}