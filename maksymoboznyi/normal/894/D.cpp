#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 5e6 + 5;

int n, m, to[N];
vector<int> t[N];
vector<int> pref[N];

void merge(vector<int> &t, vector<int> &a, vector<int> &b, int x, int y) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
        if (a[i] + x < b[j] + y)
            t.pb(a[i] + x), i++;
        else
            t.pb(b[j] + y), j++;
    while (i < a.size())
        t.pb(a[i] + x), i++;
    while (j < b.size())
        t.pb(b[j] + y), j++;
}

void build(int v) {
    if (v + v <= n)
        build(v + v);
    if (v + v + 1 <= n)
        build(v + v + 1);
    t[v].pb(0);
    merge(t[v], t[v + v], t[v + v + 1], to[v + v], to[v + v + 1]);
    pref[v].resize(t[v].size());
    pref[v][0] = t[v][0];
    for (int i = 1; i < t[v].size(); i++)
        pref[v][i] = pref[v][i - 1] + t[v][i];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        cin >> to[i + 1];
    build(1);
    for (int i = 1; i <= m; i++) {
        int a, h;
        cin >> a >> h;
        int ans = 0;
        int pos = upper_bound(t[a].begin(), t[a].end(), h) - t[a].begin() - 1;
        if (pos >= 0)
            ans += h * (pos + 1) - pref[a][pos];
        h -= to[a];
        int preva = a;
        a /= 2;
        //cout << ans << endl;
        while (a != 0) {
            if (h >= 0)
                ans += h;
            //cout << ans << endl;
            if (preva != a + a + 1) {
                h -= to[a + a + 1];
                int pos = upper_bound(t[a + a + 1].begin(), t[a + a + 1].end(), h) - t[a + a + 1].begin() - 1;
                if (pos >= 0)
                    ans += h * (pos + 1) - pref[a + a + 1][pos];
                h += to[a + a + 1];
            }

            if (preva != a + a) {
                h -= to[a + a];
                int pos = upper_bound(t[a + a].begin(), t[a + a].end(), h) - t[a + a].begin() - 1;
                //cout << pos << ' ' << a + a << endl;
                if (pos >= 0)
                    ans += h * (pos + 1) - pref[a + a][pos];
                h += to[a + a];
            }
            h -= to[a];
            preva = a;
            a /= 2;
        };
        cout << ans << "\n";
    }
    return 0;
}