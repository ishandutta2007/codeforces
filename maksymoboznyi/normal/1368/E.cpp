#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int n, m, del[N];
vector<int> g[N];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            g[i].clear(), del[i] = 0;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[b].pb(a);
        }
        for (int i = 1; i <= n; i++)
            for (auto x: g[i])
                if (!del[x])
                    for (auto y: g[x])
                        if (!del[y])
                            del[i] = 1;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (del[i] == 1)
                ans.pb(i);
        cout << ans.size() << "\n";
        for (auto x: ans)
            cout << x << ' ' ;
        cout << "\n";
    }
    return 0;
}