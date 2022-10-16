#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

const int MAX_N = 5e5;
bool used[1 + MAX_N];
multiset <pair <int, int>> activeCustomers;
int value[1 + MAX_N];

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    multiset <pair <int, int>> activeCustomers;
    int nr = 0;
    queue <int> q;
    int cur = 1;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            int m;
            cin >> m;
            value[++nr] = m;
            activeCustomers.insert ({m, -nr});
        }
        if (type == 2) {
            while (cur <= nr && used[cur])
                cur++;
            cout << cur << " ";
            activeCustomers.erase ({value[cur], -cur});
            used[cur] = true;
        }
        if (type == 3) {
            auto it = prev (activeCustomers.end ());
            used[-(it->second)] = true;
            cout << -(it->second) << " ";
            activeCustomers.erase (it);
        }
    }
    return 0;
}