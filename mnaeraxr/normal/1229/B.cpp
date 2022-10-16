#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int64 gcd(int64 a, int64 b){
    while (b){
        int64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int answer;

void add(int64 v){
    answer += v;
    if (answer >= mod)
        answer -= mod;
}

void dfs(int s, int p, int h, vector<pii> cur, vector<int64> &val, vector<vi> &tree){
    // cout << s << " " << p << " " << h << endl;
    cout.flush();
    vector<pii> nxt;
    int last = 0;

    for (auto u : cur){
        int64 g = gcd(u.first, val[s]);

        add(1LL * (u.second - last) * g % mod);
        last = u.second;

        if (!nxt.empty() && nxt.back().first == g){
            nxt.back().second = last;
        } else {
            nxt.push_back({g, last});
        }
    }

    int64 g = val[s];
    add(val[s] % mod);

    if (!nxt.empty() && nxt.back().first == g){
        nxt.back().second = h;
    } else {
        nxt.push_back({g, h});
    }

    for (auto u : tree[s]){
        if (u == p) continue;
        dfs(u, s, h + 1, nxt, val, tree);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int64> val(n);

    for (int i = 0; i < n; ++i)
        cin >> val[i];

    vector<vi> tree(n);

    for (int i = 0; i + 1 < n; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1, 1, {}, val, tree);

    cout << answer << endl;

    return 0;
}