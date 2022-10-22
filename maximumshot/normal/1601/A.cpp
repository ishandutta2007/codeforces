#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> d(n + 1);
    for (int p = 1; p <= n; p++) {
        for (int x = p; x <= n; x += p)
            d[x].push_back(p);
    }
    vector<int> can(n + 1);
    int hlp = 0;
    for (int j = 0; j < 30; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((1 << j) & a[i])
                cnt++;
        }
        for (int p : d[cnt])
            can[p]++;
        if (cnt > 0)
            hlp++;
    }
    for (int k = 1; k <= n; k++) {
        if (can[k] == hlp)
            cout << k << " ";
    }
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    work();

    return 0;
}