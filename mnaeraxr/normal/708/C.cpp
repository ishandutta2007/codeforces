#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 400010;

int bit[maxn];

void update(int idx, int v){
    while (idx < maxn){
        bit[idx] += v;
        idx += idx & -idx;
    }
}

int query(int idx){
    int ans = 0;
    while (idx > 0){
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int n;
vi tree[maxn];
int children[maxn];

void calc_children(int s, int f = -1, bool upd=true){
    children[s] = 1;

    for (auto u : tree[s]){
        if (u == f) continue;
        calc_children(u, s, upd);
        children[s] += children[u];
    }

    if (upd) update(children[s], +1);
}

void change_value(int s, int f, int v){
    update(children[s], v);

    for (auto u : tree[s]){
        if (u == f) continue;
        change_value(u, s, v);
    }
}

bool ans[maxn];

void calculate(int s, int f){
    int total = n - children[s];

    ans[s] |= ((total * 2 <= n) || ((query(n / 2) - query(total - n / 2 - 1)) > 0));

    for (auto u : tree[s]){
        if (u == f) continue;
        calculate(u, s);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    calc_children(1, -1, false);

    vector<int> centroids;

    for (int i = 1; i <= n; ++i){
        int tot = n - children[i];

        if (tot * 2 > n) continue;
        bool ok = true;

        for (auto u : tree[i]){
            int tot;
            if ((children[u] < children[i]) && (children[u] * 2 > n)){
                ok = false;
                break;
            }
        }

        if (ok) centroids.push_back(i);
    }

    // cout << "centroid: " << c << endl;

    for (auto c : centroids){
        memset(bit, 0, sizeof bit);

        calc_children(c);

        ans[c] = true;

        for (auto u : tree[c]){
            change_value(u, c, -1);
            calculate(u, c);
            change_value(u, c, +1);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}