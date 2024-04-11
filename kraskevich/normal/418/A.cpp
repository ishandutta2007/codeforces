#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int INF = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<pii> ans;
    vector<vector<bool> > was(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        int p = 0;
        int cnt = 0;
        while (cnt < k) {
            while (p < n && (p == i || was[p][i]))
                p++;
            if (p == n) {
                cout << -1;
                return 0;
            }
            was[i][p] = was[p][i] = true;
            ans.push_back(pii(i + 1, p + 1));
            cnt++;
        }
    }
    cout << ans.size() << "\n";
    for (pii x : ans)
        cout << x.F << " " << x.S << "\n";

    return 0;
}