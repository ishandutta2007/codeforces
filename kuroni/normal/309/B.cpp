#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, r, c, cur = -1, nxt[N];
bool chk[N];
pair<int, int> ans = {0, 0};
vector<int> ve, adj[N];
string s[N];

void DFS(int u) {
    chk[u] = true;
    ve.push_back(u);
    ans = max(ans, {ve[max(0, (int)ve.size() - r - 1)] - u, u});
    for (int &v : adj[u]) {
        if (v != u) {
            DFS(v);
        }
    }
    ve.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r >> c;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i <= c; i++) {
        s[n].push_back('0');
    }
    for (int i = 0, pt = 0; i <= n; i++) {
        while (pt <= n && cur <= c) {
            cur += s[pt++].size() + 1;
        }
        nxt[i] = pt - 1;
        adj[pt - 1].push_back(i);
        cur -= s[i].size() + 1;
    }
    for (int i = n; i >= 0; i--) {
        if (!chk[i]) {
            DFS(i);
        }
    }
    for (int i = 0, cur = ans.second; i < r && cur < n && cur < nxt[cur]; i++, cur = nxt[cur]) {
        for (int j = cur; j < nxt[cur] - 1; j++) {
            cout << s[j] << " ";
        }
        cout << s[nxt[cur] - 1] << '\n';
    }
}