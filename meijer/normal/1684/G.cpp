#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int n, m;
int t[N];
vector<int> ltr[N], rtl[N];

int mt[N], used[N];

bool try_kuhn(int u) {
    if (used[u])
        return 0;
    used[u] = 1;
    for (int v : ltr[u]) {
        if (mt[v] == -1 || try_kuhn(mt[v])) {
            mt[v] = u;
            return 1;
        }
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> t[i];
    
    vector<int> left, right;
    for (int i=0; i<n; i++) {
        if (t[i] <= m/3) {
            right.push_back(i);
        } else {
            left.push_back(i);
        }
    }

    for (int i : left) {
        for (int j : right) {
            int x = t[i];
            int y = t[j];
            if (x % y == 0 && 2*x + y <= m) {
                ltr[i].push_back(j);
                rtl[j].push_back(i);
            }
        }
    }

    int combined = 0;
    fill(mt,mt+n,-1);
    for (int v=0; v<n; v++) {
        fill(used,used+n,0);
        if (try_kuhn(v)) {
            combined++;
        }
    }

    if (combined != left.size()) {
        cout << -1 << endl;
        return 0;
    }

    cout << right.size() << endl;
    for (int v : right) {
        if (mt[v] == -1) {
            cout << t[v]*3 << " " << t[v]*2 << endl;
        } else {
            int u = mt[v];
            cout << 2*t[u] + t[v] << " " << t[u] + t[v] << endl;
        }
    }
}