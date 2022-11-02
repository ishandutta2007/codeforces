#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

const int maxn = 200100;

int n;
vector<pair<int, int> > adj[maxn];
bool vis[maxn];
pair<int, int> stk[maxn]; int stksze;
pair<int, int> cyc[maxn]; int cycsze;
bool incyc[maxn];

void dfs(int v, pair<int, int> p = MP(-1, -1)) {
    vis[v] = 1;
    stk[stksze++] = MP(v, p.B);
    for (auto i : adj[v]) {
        if (cycsze > 0) return;
        if (i.A == p.A) continue;
        if (!vis[i.A]) dfs(i.A, MP(v, i.B));
        else {
            if (cycsze > 0) return;
            while (stk[stksze - 1].A != i.A) {
                cyc[cycsze++] = stk[--stksze];
            }
            cyc[cycsze++] = i;
        }
    }
    if (cycsze > 0) return;
    stksze--;
}

ll mal;
ll ml[maxn];

void dfs2(int v, int p = -1) {
    ml[v] = 0;
    vector<ll> vl;
    for (auto i : adj[v]) {
        if (i.A == p) continue;
        if (incyc[i.A]) continue;
        dfs2(i.A, v);
        ml[v] = max(ml[v], ml[i.A] + i.B);
        vl.push_back(ml[i.A] + i.B);
    }

    sort(vl.begin(), vl.end()); reverse(vl.begin(), vl.end());
    mal = max(mal, ml[v]);
    if (vl.size() > 1) mal = max(mal, vl[0] + vl[1]);
}

ll pre[2 * maxn];

const ll inf = 1e18;
const int S = 1<<19;

struct data {
    ll bl, br, b;

    void merge(const data& d) {
        ll bl2 = max(bl, d.bl);
        ll br2 = max(br, d.br);
        ll b2 = max(max(b, d.b), bl + d.br);
        bl = bl2, br = br2, b = b2;
    }

} t[2 * S];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        int i = lt - (lt >= cycsze ? cycsze : 0);
        t[cur].bl = ml[cyc[i].A] - pre[lt];
        t[cur].br = ml[cyc[i].A] + pre[lt];
        t[cur].b = ml[cyc[i].A];
        //cout << t[cur].bl << ' ' << t[cur].br << ' ' << t[cur].b << endl;
    } else {
        int mid = (lt + rt) / 2;
        init(2 * cur, lt, mid);
        init(2 * cur + 1, mid, rt);
        t[cur] = t[2 * cur];
        t[cur].merge(t[2 * cur + 1]);
        //cout << t[cur].bl << ' ' << t[cur].br << ' ' << t[cur].b << endl;
    }
}

data qry(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) {
        data ret = data();
        ret.bl = ret.br = ret.b = -inf;
        return ret;
    } else if (lt >= ql && rt <= qr) return t[cur];
    else {
        int mid = (lt + rt) / 2;
        data ret = qry(2 * cur, lt, mid, ql, qr);
        ret.merge(qry(2 * cur + 1, mid, rt, ql, qr));
        //cout << ret.bl << ' ' << ret.br << ' ' << ret.b << endl;
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(MP(b, c));
        adj[b].push_back(MP(a, c));
    }

    dfs(1);
    for (int i = 0; i < cycsze; i++) incyc[cyc[i].A] = 1;

    for (int i = 0; i < cycsze; i++) dfs2(cyc[i].A);

    //for (int i = 0; i < cycsze; i++) cout << cyc[i].A << ' ' << ml[cyc[i].A] << ' ' << cyc[i].B << endl;

    ll ans = inf;

    for (int i = 0; i < 2 * cycsze; i++) {
        int j = i - (i >= cycsze ? cycsze : 0);
        pre[i + 1] = pre[i] + cyc[j].B;
    }

    init(1, 0, 2 * cycsze);

    for (int i = 0; i < cycsze; i++) {
        data res = qry(1, 0, 2 * cycsze, i, i + cycsze);
        //cout << res.bl << ' ' << res.br << ' ' << res.b << endl;
        ans = min(ans, res.b);
    }

    ans = max(ans, mal);
    cout << ans << '\n';
}