#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

bool hasPink[maxn];
bool pink[maxn];
vector<int> answer;
vi adj[maxn];

void push(int a){
    pink[a] ^= 1;
    answer.push_back(a);
}

void dfs1(int u, int p){
    hasPink[u] = pink[u];

    for (auto v : adj[u]){
        if (v != p){
            dfs1(v, u);
            hasPink[u] |= hasPink[v];
        }
    }
}

void dfs2(int u, int p){
    for (auto v : adj[u]){
        if (v == p) continue;

        if (hasPink[v]){
            push(v);
            dfs2(v, u);
            push(u);
        }
    }

    if (pink[u]){
        if (u == 1 && p == 1){
            push(adj[1][0]);
            push(1);
            push(adj[1][0]);
        }
        else{
            push(p);
            push(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n; cin >> n;

    for (int i = 1; i <= n; ++i){
        int v; cin >> v;
        pink[i] = v == -1;
    }

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 1);

    push(1);
    pink[1] ^= 1;

    dfs2(1, 1);

    // for (int i = 0; i < cnt; ++i)
    //     cout << answer[i] << " ";
    for (auto x : answer)
        cout << x << " ";
    cout << endl;

    return 0;
}