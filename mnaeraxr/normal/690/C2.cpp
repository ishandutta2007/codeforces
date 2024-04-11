#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

vi adj[maxn];

pii farthest(int a, int p = -1){
    pii ans(0, a);

    for (auto v : adj[a]) if (v != p){
        pii cur = farthest(v, a);

        if (cur.first + 1 > ans.first){
            ans = {cur.first + 1, cur.second};
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pii f = farthest(1);
    pii a = farthest(f.second);

    cout << a.first << endl;

    return 0;
}