
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, a[N][2], inst[N][2];
vi adj[2 * N], cnt[N];
bool vis[2 * N];
vi ve;

void dfs(int x) {
    ve.push_back(x);
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 1, n + 1) cnt[i].clear();
        rep(i, 0, 2 * n) adj[i].clear();
        rep(i, 0, n) {
            cin >> a[i][0];
            inst[i][0] = sz(cnt[a[i][0]]);
            cnt[a[i][0]].push_back(i);
        }
        rep(i, 0, n) {
            cin >> a[i][1];
            inst[i][1] = sz(cnt[a[i][1]]);
            cnt[a[i][1]].push_back(n + i);
        }
        bool flag = false;
        rep(i, 1, n + 1) {
            if(sz(cnt[i]) != 2) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cout << "-1\n";
            continue;
        }
        rep(i, 1, n + 1) {
            adj[cnt[i][0]].push_back(cnt[i][1]);
            adj[cnt[i][1]].push_back(cnt[i][0]);
        }
        rep(i, 0, n) {
            adj[i].push_back(n + i);
            adj[n + i].push_back(i);
        }
        int cost = 0;
        fill(vis, vis + 2 * n, false);
        vi pos;
        rep(i, 0, 2 * n) {
            if(!vis[i]) {
                ve.clear();
                dfs(i);
                int c[2] = {0, 0};
                rep(j, 0, sz(ve)) {
                    c[(j % 2) ^ (ve[j] >= n)]++;
                }
                if(c[0] < c[1]) {
                    cost += c[0];
                    rep(j, 0, sz(ve)) {
                        if(((j % 2) ^ (ve[j] >= n)) == 0 && ve[j] < n) {
                            pos.push_back(ve[j] + 1);
                        }
                    }
                }else {
                    cost += c[1];
                    rep(j, 0, sz(ve)) {
                        if(((j % 2) ^ (ve[j] >= n)) == 1 && ve[j] < n) {
                            pos.push_back(ve[j] + 1);
                        }
                    }
                }
            }
        }
        cout << cost / 2 << '\n';
        for(int x : pos) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}