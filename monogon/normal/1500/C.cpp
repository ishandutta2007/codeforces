
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct node {
    map<int, int> go;
};

vector<node> e;

int add_node() {
    int k = sz(e);
    e.push_back(node());
    return k;
}
int nxt(int x, int y) {
    if(e[x].go.count(y) == 0) e[x].go[y] = add_node();
    return e[x].go[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int root = add_node();
    rep(i, 0, n) {
        int x = root;
        rep(j, 0, m) {
            int a;
            cin >> a;
            x = nxt(x, a);
        }
        x = nxt(x, i);
    }
    bool flag = false;
    vector<vi> b(n, vi(m + 1, 0));
    rep(i, 0, n) {
        int x = root;
        rep(j, 0, m) {
            cin >> b[i][j];
            if(e[x].go.count(b[i][j]) == 0) flag = true;
            else x = nxt(x, b[i][j]);
        }
        if(e[x].go.empty()) flag = true;
        else {
            b[i][m] = e[x].go.begin()->first;
            e[x].go.erase(e[x].go.begin());
        }
    }
    if(flag) {
        cout << -1 << '\n';
        return 0;
    }
    flag = false;
    vi cnt(m + 1, 0), ans;
    rep(i, 1, n) rep(j, 0, m + 1) {
        if(b[i][j] < b[i - 1][j]) {
            cnt[j]++;
        }
    }
    queue<int> Q;
    rep(i, 0, m + 1) if(cnt[i] == 0) Q.push(i);
    vector<bool> vis(n, false);
    while(!Q.empty()) {
        int j = Q.front(); Q.pop();
        if(j == m) {
            flag = true;
            break;
        }
        ans.push_back(j);
        rep(i, 1, n) {
            if(!vis[i] && b[i][j] != b[i - 1][j]) {
                vis[i] = true;
                rep(k, 0, m + 1) {
                    if(b[i][k] < b[i - 1][k]) {
                        cnt[k]--;
                        if(cnt[k] == 0) Q.push(k);
                    }
                }
            }
        }
    }

    if(!flag) {
        cout << -1 << '\n';
        return 0;
    }
    reverse(all(ans));
    cout << sz(ans) << '\n';
    for(int x : ans) cout << x + 1 << ' ';
    cout << '\n';
}