#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 2;
const int M = 998244353;

int ans, u[N], n, p[N], c[N], used[N];
vector<int> cycle;

void go() {
    vector<int> del;
    for (int i = 1; i <= cycle.size(); i++)
        if (cycle.size() % i == 0)
            del.pb(i);
    for (auto d: del) {
        //cout << "FWGGAF" << d << endl;
        for (int i = 0; i < cycle.size(); i++)
            u[i] = 0;
        for (int i = 0; i < cycle.size(); i++)
            if (!u[i]) {
                int cur = i;
                bool can = 1;
                u[i] = 1;
                while (!u[(cur + d) % cycle.size()]) {
                    if (c[cycle[(cur + d) % cycle.size()]] == c[cycle[cur]])
                        cur = (cur + d) % cycle.size(), u[cur] = 1;
                    else {
                        can = 0;
                        cur = (cur + d) % cycle.size(), u[cur] = 1;
                    }
                    //cout << cur << ' ' << cycle[cur] << ' ' << can << endl;
                }
                //cout << endl << endl;
                if (can)
                    ans = min(ans, d);
            }
    }
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
            used[i] = 0, cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        ans = n;
        for (int i = 1; i <= n; i++)
            if (!used[i]) {
                cycle.clear();
                cycle.pb(i);
                used[i] = 1;
                while (!used[p[cycle.back()]])
                    cycle.pb(p[cycle.back()]), used[cycle.back()] = 1;
                go();
            }
        cout << ans << "\n";
    }

    return 0;
}