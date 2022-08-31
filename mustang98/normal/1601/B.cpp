#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

vector<pair<int, int>> v[5 * max_n];

void add_edge(int from, int to, int w) {
    //cout << "$ " << from << ' ' << to << endl;
    v[from].emplace_back(to, w);
}

int n;

int m[max_n];
int val[5 * max_n];
struct segment_tree {
    void build(int cur, int l, int r) {
        if (l == r) {
            val[n + cur] = l;
            add_edge(n + cur, m[l], 0);
            return;
        }
        int mid = (l + r) / 2;
        add_edge(n + cur, n + cur * 2, 0);
        add_edge(n + cur, n + cur * 2 + 1, 0);
        build(cur * 2, l, mid);
        build(cur * 2 + 1 , mid + 1, r);
    }

    void add(int cur, int l, int r, int ql, int qr, int from) {
        if (qr < l || ql > r) {
            return;
        }
        if (ql == l && qr == r) {
            add_edge(from, n + cur, 1);
            return;
        }
        int mid = (l + r ) / 2;
        add(cur * 2, l, mid, ql, min(mid, qr), from);
        add(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr, from);
    }

} tr;

int a[max_n];
int b[max_n];
int pr[5 * max_n];
int d[5 * max_n];
bool vis[5 * max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5 * max_n; ++i) {
        val[i] = -1;
    }
    cin >> n;
    ++n;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
        m[i] = i + b[i];
    }
    tr.build(1, 0, n - 1);
    for (int i = 1; i < n; ++i) {
        int l = max(0, i - a[i]), r = i;
        tr.add(1, 0, n - 1, l, r, i);
    }
    for (int i = 0; i < 5 * max_n; ++i) {
        d[i] = inf;
    }
    d[n - 1] = 0;
    deque<int> q;
    q.push_back(n - 1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop_front();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (pair<int, int> p : v[cur]) {
            int to = p.F, w = p.S;
            if (!vis[to] && d[to] > d[cur] + w) {
                d[to] = d[cur] + w;
                pr[to] = cur;
                if (w == 0) q.push_front(to);
                else q.push_back(to);
            }
        }
    }
    if (d[0] == inf) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int cur = 0;
    while(cur != n-1) {
        if (val[cur] != -1) {
            ans.PB(val[cur]);
        }
        cur = pr[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << d[0] << endl;
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}