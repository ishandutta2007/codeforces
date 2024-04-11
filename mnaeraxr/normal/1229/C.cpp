#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int64 answer = 0;

    vector<int> deg(n);
    vector<vi> bigger(n);

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        if (u < v) swap(u, v);

        bigger[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    auto center = [&](int u){
        int big = bigger[u].size();
        int low = deg[u] - big;
        return 1LL * big * low;
    };

    for (int i = 0; i < n; ++i){
        answer += center(i);
    }

    cout << answer << endl;

    int q; cin >> q;

    while (q-->0){
        int u; cin >> u; u--;

        answer -= center(u);

        for (auto v : bigger[u]){
            answer -= center(v);
            bigger[v].push_back(u);
            answer += center(v);
        }

        bigger[u].clear();

        cout << answer << endl;
    }

    return 0;
}