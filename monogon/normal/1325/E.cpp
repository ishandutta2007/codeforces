
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];
vector<int> v[N];
vector<int> p;
bool unit[2 * N];
vector<int> adj[2 * N];
bool vis[2 * N];
int dist[2 * N];

vector<int> check(int x) {
    vector<int> ans;
    for(int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            int d = 0;
            while(x % i == 0) {
                x /= i;
                d++;
            }
            if(d % 2) {
                ans.push_back(i);
            }
        }
    }
    if(x > 1) {
        ans.push_back(x);
    }
    return ans;
}

int solve() {
    int ans = INT_MAX;
    for(int i = 0; i < (int) p.size(); i++) {
        if(p[i] > 1000) break;
        fill(vis, vis + (int) p.size(), false);
        fill(dist, dist + (int) p.size(), INT_MAX);
        vis[i] = true;
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        int mincycle = INT_MAX;
        vector<int> dists;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            if(unit[x]) {
                dists.push_back(dist[x]);
            }
            for(int y : adj[x]) {
                if(!vis[y]) {
                    vis[y] = true;
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }else if(dist[y] == dist[x]) {
                    mincycle = min(mincycle, dist[y] + dist[x] + 1);
                }else if(dist[y] == dist[x] + 1) {
                    mincycle = min(mincycle, dist[y] * 2);
                }
            }
        }
        if(dists.size() >= 2) {
            ans = min(ans, dists[0] + dists[1] + 2);
        }
        ans = min(ans, mincycle);
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = check(a[i]);
        st.insert(a[i]);
        if(v[i].empty()) {
            cout << 1 << endl;
            return 0;
        }
        for(int x : v[i]) p.push_back(x);
    }
    if((int) st.size() < n) {
        cout << 2 << endl;
        return 0;
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 0; i < n; i++) {
        if(v[i].size() == 1) {
            int j = lower_bound(p.begin(), p.end(), v[i][0]) - p.begin();
            if(unit[j]) {
                cout << 2 << endl;
                return 0;
            }
            unit[j] = true;
        }else {
            int j = lower_bound(p.begin(), p.end(), v[i][0]) - p.begin();
            int k = lower_bound(p.begin(), p.end(), v[i][1]) - p.begin();
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
    }
    int ans = solve();
    cout << ans << endl;
}