
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int N = 3e5 + 5;
int n, h[N];
vi adj[N];
bool vis[N];
int dist[N];

void dostuff(vector<pii> &ve) {
    set<int> se;
    rep(uwu, 0, n) {
        int H, idx;
        tie(H, idx) = ve[uwu];
        auto it = se.lower_bound(idx);
        if(it != se.begin()) {
            adj[*prev(it)].push_back(idx);
        }
        if(it != se.end() && (uwu == n - 1 || ve[uwu+1].first != H || ve[uwu+1].second > *it)) {
            adj[idx].push_back(*it);
        }
        se.insert(idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> h[i];
        ve.emplace_back(h[i], i);
    }
    sort(all(ve));
    dostuff(ve);
    rep(i, 0, n) {
        ve[i] = {-ve[i].first, ve[i].second};
    }
    sort(all(ve));
    dostuff(ve);
    queue<int> Q;
    vis[0] = true;
    Q.push(0);
    /*rep(i, 0, n) {
        for(int x : adj[i]) {
            cout << i << ' ' << x << endl;
        }
    }*/
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int y : adj[x]) {
            if(!vis[y]) {
                dist[y] = dist[x] + 1;
                vis[y] = true;
                Q.push(y);
            }
        }
    }
    cout << dist[n - 1] << '\n';
}