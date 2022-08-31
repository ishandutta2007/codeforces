#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;
const ll inf = 1000111222LL * 1000111222LL;
int n, q, s;
vector<pair<int, int> > v[9 * max_n];
ll d[9 * max_n];
bool vis[9 * max_n];

struct segment_tree2 {
    int tr[4 * max_n];
    void add(int from, int to) {
        v[n + from - 1].pb(mp(n + to - 1, 0));
    }
    void build(int cur, int l, int r) {
        if (l == r) {
            v[n + cur - 1].pb(mp(l, 0));
            return;
        }
        add(cur, cur * 2);
        add(cur, cur * 2 + 1);
        int mid = (l + r) / 2;

        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
    }
    void setedge(int cur, int l, int r, int ql, int qr, int from, int w) {
        if (l == ql && r == qr) {
            v[from].pb(mp(n + cur - 1, w));
            return;
        }
        if (l > qr || r < ql) {
            return;
        }
        int mid = (l + r) / 2;
        setedge(cur * 2, l, mid, ql, min(qr, mid), from, w);
        setedge(cur * 2 + 1, mid + 1, r, max(ql, mid + 1), qr, from, w);
    }
} st2;

struct segment_tree3 {
    int tr[4 * max_n];
    void add(int from, int to) {
        v[5 * n + from].pb(mp(5 * n + to, 0));
    }
    void build(int cur, int l, int r) {
        if (l == r) {
            v[l].pb(mp(5 * n + cur, 0));
            return;
        }
        add(cur * 2, cur);
        add(cur * 2 + 1, cur);
        int mid = (l + r) / 2;

        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
    }
    void setedge(int cur, int l, int r, int ql, int qr, int to, int w) {
        if (l == ql && r == qr) {
            v[5 * n + cur].pb(mp(to, w));
            return;
        }
        if (l > qr || r < ql) {
            return;
        }
        int mid = (l + r) / 2;
        setedge(cur * 2, l, mid, ql, min(qr, mid), to, w);
        setedge(cur * 2 + 1, mid + 1, r, max(ql, mid + 1), qr, to, w);
    }
} st3;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> q >> s;
    st2.build(1, 0, n - 1);
    st3.build(1, 0, n - 1);
    --s;
    int type, from1, from2, to1, to2, w;
    for (int i = 0; i < q; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> from1 >> to1 >> w;
            --from1, --to1;
            v[from1].pb(mp(to1, w));
        } else if (type == 2) {
            cin >> from1 >> to1 >> to2 >> w;
            --from1, --to1, --to2;
            st2.setedge(1, 0, n - 1, to1, to2, from1, w);
        } else {
            cin >> to1 >> from1 >> from2 >> w;
            --from1, --from2, --to1;
            st3.setedge(1, 0, n - 1, from1, from2, to1, w);
        }
    }
    n *= 9;
    for (int i = 0; i < n; ++i) {
        d[i] = inf;
    }
    d[s] = 0;
    priority_queue<pair<ll, int> > q;
    q.push(mp(0, s));
    while (!q.empty()) {
        int cur = q.top().S;
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (int i = 0; i < v[cur].size(); ++i) {
            int to = v[cur][i].F;
            int w = v[cur][i].S;
            if (d[to] > d[cur] + w) {
                d[to] = d[cur] + w;
                q.push(mp(-d[to], to));
            }
        }
    }
    for (int i = 0; i < n / 9; ++i){
        cout << (d[i] == inf ? -1 : d[i]) << ' ';
    }
    return 0;
}