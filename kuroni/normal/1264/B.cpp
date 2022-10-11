#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 5E5 + 5;

int a[4], b[4], cnt;
bool chk[N];
vector<int> ve;
vector<pair<int, int>> adj[4];

void DFS(int u) {
    while (!adj[u].empty()) {
        pair<int, int> &v = adj[u].back(); adj[u].pop_back();
        if (chk[v.fi]) {
            continue;
        }
        chk[v.fi] = true;
        DFS(v.se);
    }
    ve.push_back(u);
}

bool construct(int st, int en) {
    ve.clear();
    for (int i = 0; i <= cnt; i++) {
        chk[i] = false;
    }
    cnt = 0;
    for (int i = 0; i < 4; i++) {
        b[i] = a[i] * 2;
        if (i == st) {
            b[i]--;
        }
        if (i == en) {
            b[i]--;
        }
        adj[i].clear();
    }
    for (int i = 0; i < 3; i++) {
        if (b[i] > b[i + 1]) {
            return false;
        }
        b[i + 1] -= b[i];
        for (int j = 0; j < b[i]; j++) {
            adj[i].push_back({cnt, i + 1});
            adj[i + 1].push_back({cnt, i});
            cnt++;
        }
    }
    if (b[3] > 0) {
        return false;
    }
    adj[st].push_back({cnt, en});
    adj[en].push_back({cnt, st});
    DFS(st);
    ve.pop_back();
    if (ve.size() < a[0] + a[1] + a[2] + a[3]) {
        return false;
    }
    cout << "YES\n";
    for (int i = 0; i < ve.size(); i++) {
        if (ve[i] == st && ve[(i + 1) % ve.size()] == en) {
            for (int j = 0; j < ve.size(); j++) {
                cout << ve[(i + j + 1) % ve.size()] << " ";
            }
            return true;
        } else if (ve[i] == en && ve[(i + 1) % ve.size()] == st) {
            for (int j = 0; j < ve.size(); j++) {
                cout << ve[(i + j + 1) % ve.size()] << " ";
            }
            return true;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int st = 0; st < 4; st++) {
        for (int en = st; en < 4; en++) {
            if (a[st] > 0 && a[en] > 0 && construct(st, en)) {
                return 0;
            }
        }
    }
    cout << "NO\n";
}