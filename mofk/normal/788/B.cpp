#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
int dad[1000006];
int deg[1000006];
int self[1000006];

int anc(int u) { if (dad[u] == u) return u; return dad[u] = anc(dad[u]); }
void join(int u, int v) { dad[anc(v)] = anc(u); }

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ff(i, 1, N) dad[i] = i;
    int u, v;
    ff(i, 1, M) {
        cin >> u >> v;
        if (u == v) { ++self[u]; continue; }
        ++deg[u]; ++deg[v];
        join(u, v);
    }
    int cc = 0;
    ff(i, 1, N) if ((deg[i] + self[i]) && dad[i] == i) ++cc;
    if (cc > 1) return cout << 0 << endl, 0;
    ll ans = 0;
    int Self = 0; ff(i, 1, N) Self += self[i];
    ff(i, 1, N) ans += 1ll * deg[i] * (deg[i] - 1) / 2;
    ans += 1ll * Self * (M - Self);
    ans += 1ll * Self * (Self - 1) / 2;
    cout << ans << endl;
    return 0;
}