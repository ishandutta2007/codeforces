#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

struct disjointset {
    vector<int> ds;

    disjointset(int n) {
        ds = vector<int>(n, -1);
    }

    int root(int a) {
        return ds[a] < 0 ? a : ds[a] = root(ds[a]);
    }

    bool join(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (ds[u] < ds[v]) swap(u, v);
        ds[u] += ds[v];
        ds[v] = u;
        return true;
    }

    int size(int u) {
        return -ds[root(u)];
    }
};

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> p(n);
    multiset<int> s;

    disjointset ds(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        p[a[i]] = i;
        s.insert(1);
    }

    for (int i = 0; i < n; ++i) {
        int ix = p[i];

        auto ul = ds.size(ix);

        if (ds.size(ix) != *s.rbegin()) {
            cout << "No" << endl;
            return;
        }

        s.erase(s.find(ds.size(ix)));
        int nx = ix + ds.size(ix + 1);

        if (nx < n) {
            s.erase(s.find(ds.size(ix + 1)));
            ds.join(ix, ix + 1);
            s.insert(ds.size(ix));
        } else {
            ds.join(ix, ix + 1);
        }
    }

    cout << "Yes" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}