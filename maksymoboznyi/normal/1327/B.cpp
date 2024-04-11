#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 2;

int n, can[N], used[N];
vector<int> g[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            g[i].resize(k);
            for (int j = 0; j < k; j++)
                cin >> g[i][j];
        }
        for (int i = 1; i <= n; i++)
            can[i] = used[i] = 0;
        int k_base = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < g[i].size(); j++)
                if (!used[g[i][j]]) {
                    k_base++;
                    used[g[i][j]] = 1;
                    can[i] = 1;
                    break;
                }

        }
        if (k_base == n)
            cout << "OPTIMAL\n";
        else {
            cout << "IMPROVE\n";
            for (int i = 1; i <= n; i++)
            if (!can[i]) {
                cout << i << ' ' ;
                break;
            }
            for (int i = 1; i <= n; i++)
            if (!used[i]) {
                cout << i;
                break;
            }
            cout << "\n";
        }
    }
    return 0;
}