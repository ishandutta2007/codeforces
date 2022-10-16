#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[200005];
vector <int> pos[200005];
int mq[200005][20];
set <int> s;

int rmq(int l, int r) {
    int k = log2(r - l + 1);
    return min(mq[l][k], mq[r - (1<<k) + 1][k]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        mq[i][0] = a[i] == 0 ? q + 1 : a[i];
        if (a[i] == 0) s.insert(i);
    }
    if (s.size() == n) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i) cout << q << ' ';
        cout << endl;
        return 0;
    }
    for (int j = 1; j < 18; ++j) for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        mq[i][j] = min(mq[i][j-1], mq[i + (1 << j-1)][j-1]);
    for (int i = q; i >= 1; --i) {
        if (pos[i].empty()) {
            if (i < q) continue;
            if (s.empty()) return cout << "NO" << endl, 0;
            a[*s.begin()] = i;
            s.erase(s.begin());
            continue;
        }
        int l = pos[i][0], r = pos[i].back();
        if (rmq(l, r) < i) return cout << "NO" << endl, 0;
        auto it = s.lower_bound(l);
        while (it != s.end() && *it <= r) {
            a[*it] = i;
            s.erase(it);
            it = s.lower_bound(l);
        }
    }
    for (int i = 1; i <= n; ++i) if (!a[i]) a[i] = i > 1 ? a[i-1] : 1;
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << endl;
    return 0;
}