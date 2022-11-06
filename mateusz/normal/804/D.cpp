#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, q;
int a, b;
bool vis[N];
int deepest[N], secondDeepest[N];
int rep[N];
vector<int> V[N], nodes[N];
vector<long long> pref[N];
int diam[N];
int maxDist[N];
map<pair<int, int>, long double> ans;

void DFS(int w, int comp) {
    nodes[comp].push_back(w);
    vis[w] = true;
    rep[w] = comp;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS(u, comp);
            if (deepest[u] + 1 <= deepest[w]) {
                secondDeepest[w] = max(secondDeepest[w], deepest[u] + 1);
            } else {
                secondDeepest[w] = deepest[w];
                deepest[w] = deepest[u] + 1;
            }
        }
    }
    diam[comp] = max(diam[comp], deepest[w] + secondDeepest[w]);
}

void DFS2(int w, int deepestFromAbove) {
    vis[w] = true;
    maxDist[w] = max(deepest[w], deepestFromAbove);
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            int nextDeepest = max(deepestFromAbove, deepest[u] + 1 == deepest[w] ? secondDeepest[w] : deepest[w]) + 1;
            DFS2(u, nextDeepest);
        }
    }
}

long double calcResult(int a, int b) {
    long long sum = 0;
    int threshold = max(diam[a], diam[b]);
    for (int i = 0; i < nodes[a].size(); i++) {
        int w = nodes[a][i];
        int low = 0;
        int high = nodes[b].size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int u = nodes[b][mid];
            if (maxDist[w] + maxDist[u] + 1 <= threshold) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long long belowThreshold = (long long)(res + 1) * threshold;
        long long leftSide = (long long)(nodes[b].size() - (res + 1)) * maxDist[w];
        long long rightSide = pref[b].back() - (res == -1 ? 0 : pref[b][res]);
        long long no = nodes[b].size() - (res + 1);
        sum += belowThreshold + leftSide + rightSide + no;
    }
    return (long double)sum / (long double)nodes[a].size() / (long double)nodes[b].size();
}

bool cmp(int a, int b) {
    return maxDist[a] < maxDist[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d %d %d", &n, &m, &q);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            DFS(i, i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            DFS2(i, 0);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (rep[i] < i) continue;
        sort(nodes[i].begin(), nodes[i].end(), cmp);
        if (nodes[i].size() > 0) {
            pref[i].push_back(maxDist[nodes[i][0]]);
            for (int j = 1; j < nodes[i].size(); j++) {
                pref[i].push_back(pref[i].back() + maxDist[nodes[i][j]]);
            }
        }
    }
    
    while (q--) {
        int w, u;
        scanf("%d %d", &w, &u);
        int compA = rep[w];
        int compB = rep[u];
        if (compA == compB) {
            cout << -1 << endl;
            continue;
        }
        if (nodes[compA].size() > nodes[compB].size()) {
            swap(compA, compB);
        }
        if (!ans.count(make_pair(compA, compB))) {
            ans[make_pair(compA, compB)] = calcResult(compA, compB);
        }
        cout << fixed << setprecision(10) << ans[make_pair(compA, compB)] << endl;
    }
    
    return 0;
}