#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];

vector<int> pos;
int fst[max_n];
int sz[max_n];

void dfs(int cur) {
    fst[cur] = pos.size();
    pos.PB(cur);
    sz[cur] = 1;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        dfs(to);
        sz[cur] += sz[to];
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i + 1 < n; ++i) {
        int p;
        cin >> p;
        --p;
        v[p].PB(i + 1);
    }
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int o, u;
        cin >> o >> u;
        --o, --u;
        if (u >= sz[o]) {
            cout << -1 << "\n";
        } else {
            cout << pos[fst[o] + u] + 1 << "\n";
        }
    }

    return 0;
}