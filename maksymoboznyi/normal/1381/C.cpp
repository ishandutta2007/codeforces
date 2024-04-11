#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5 + 5;

int n, a[N], used[N], x, t1, t2, ans[N];
vector<int> pos[N];
set<pair<int, int> > q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    cin >> n;
    cin >> t1 >> t2;
    for (int i = 1; i <= n + 1; i++)
        ans[i] = 0, used[i] = 0, pos[i].clear();
    q.clear();
    bool can = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i], used[a[i]] = 1, pos[a[i]].pb(i);
    for (int i = 1; i <= n + 1; i++)
        if (!used[i])
            x = i;
        else
            q.insert({pos[i].size(), i});

    t2 -= t1;
    while (t1--) {
        auto it = q.end();
        it--;
        int i = it -> second;
        ans[pos[i].back()] = i;
        pos[i].pop_back();
        q.erase(it);
        if (pos[i].size() != 0)
            q.insert({pos[i].size(), i});
    }
    vector<pair<int, int> > pp;
    while (t2 >= 2) {
        auto it = q.end();
        it--;
        int p1 = q.begin() -> second, p2 = it -> second;
        if (p1 == p2)
            break;
        t2 -= 2;
        q.erase(it);
        q.erase(q.begin());
        int x1 = pos[p1].back(), x2 = pos[p2].back();
        ans[x1] = p2;
        ans[x2] = p1;
        pp.pb({x1, x2});
        pos[p1].pop_back();
        pos[p2].pop_back();
        if (pos[p1].size() != 0)
            q.insert({pos[p1].size(), p1});
        if (pos[p2].size() != 0)
            q.insert({pos[p2].size(), p2});
    }
    if (t2 > 1) {
        cout << "NO\n";
        can = 0;
    }
    if (t2 == 1) {
        vector<int> c;
        for (int i = 1; i <= n + 1; i++)
            if (pos[i].size() > 0 && c.size() < 3)
                c.pb(i);
        for (auto [x, y] : pp)
            for (auto q: c)
                if (a[x] != q && a[y] != q)
                if (t2){
                    int pq = pos[q].back();
                    pos[q].pop_back();
                    ans[x] = q;
                    ans[pq] = a[y];
                    ans[y] = a[x];
                    t2--;
                }
        if (t2) {
            if (c.size() > 1) {
                int p1 = pos[c[0]].back(), p2 = pos[c[1]].back();
                ans[p2] = c[0];
                t2 = 0;
            } else {
                cout << "NO\n";
                can = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0)
            ans[i] = x;
    if (can) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << "\n";
    }
    }
    return 0;
}