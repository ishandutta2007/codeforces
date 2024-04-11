
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

const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, u[M], v[M], w[N], ti[N];
vi adj[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> w[i];
    }
    rep(i, 1, m + 1) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(i);
        adj[v[i]].push_back(-i);
        w[u[i]]--;
        w[v[i]]--;
    }
    queue<int> Q;
    int t = 0;
    rep(i, 1, n + 1) {
        if(w[i] >= 0) {
            Q.push(i);
            vis[i] = true;
            ti[i] = t++;
        }
    }
    vector<int> ve;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i : adj[x]) {
            int y = (i < 0 ? u[-i] : v[i]);
            i = abs(i);
            if(!vis[y]) {
                ve.push_back(i);
                w[y]++;
                if(w[y] >= 0) {
                    vis[y] = true;
                    ti[y] = t++;
                    Q.push(y);
                }
            }else if(ti[y] > ti[x]) {
                ve.push_back(i);
            }
        }
    }
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            cout << "DEAD\n";
            return 0;
        }
    }
    cout << "ALIVE\n";
    reverse(all(ve));
    for(int i : ve) {
        cout << i << ' ';
    }
    cout << '\n';
}