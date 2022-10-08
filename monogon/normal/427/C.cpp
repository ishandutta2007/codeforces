
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5, M = 1'000'000'007;
int n, m, u, v;
ll c[N];
vector<int> adj[N], adjr[N];

bool vis[N];
int cmp[N], cnt[N];
stack<int> st;

void scc1(int x) {
    vis[x] = true;
    for(int y : adj[x])
        if(!vis[y]) scc1(y);
    st.push(x);
}
void scc2(int x, int p) {
    cmp[x] = p;
    for(int y : adjr[x])
        if(cmp[y] == -1) scc2(y, p);
}
void scc() {
    for(int i = 0; i < n; i++) {
        if(!vis[i]) scc1(i);
    }
    fill(cmp, cmp + n, -1);
    while(st.size()) {
        int x = st.top();
        st.pop();
        if(cmp[x] == -1) scc2(x, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cin >> m;
    while(m--) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }
    scc();
    set<int> s;
    fill(cnt, cnt + n, 1);
    for(int i = 0; i < n; i++) {
        if(i == cmp[i]);
        else if(c[i] < c[cmp[i]]) {
            c[cmp[i]] = c[i];
            cnt[cmp[i]] = 1;
        }else if(c[i] == c[cmp[i]]) {
            cnt[cmp[i]]++;
        }
        s.insert(cmp[i]);
    }
    ll cost = 0;
    ll ans = 1;
    while(s.size()) {
        int x = *s.begin();
        cost += c[x];
        ans = (ans * cnt[x]) % M;
        s.erase(s.begin());
    }
    cout << cost << " " << ans << endl;
}