#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back

const int N = 1e5 + 10;

int n, m, cnt;
int a[N];
vector<int> nex[N];
bool visit[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        nex[u].pb(v); nex[v].pb(u);
    }
    int m1 = 0, m2 = 0;
    FOR(i, 1, n)    {
        if(nex[i].size() == n - 1) continue;
        m1 = i;
        for(int v: nex[i]) visit[v] = true;
        FOR(j, 1, n) if(j != i && !visit[j]) {
            m2 = j; break;
        }
        break;
    }
    if(!m1) return cout << "NO", 0;
    cout << "YES\n";
    cnt = 2;
    FOR(i, 1, n) {
        if(i == m1) cout << "1 ";
        else if(i == m2) cout << "2 ";
        else cout << ++cnt << ' ';
    } cout << '\n';
    cnt = 2;
    FOR(i, 1, n)    {
        if(i == m1 || i == m2) cout << "1 ";
        else cout << ++cnt << ' ';
    }
    // :D ahihi
}