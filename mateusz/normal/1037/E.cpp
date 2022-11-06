#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, a, b, m, k;
vector<pair<int, int> > V[N];
int edgeFrom[N], edgeTo[N];
bool removed[N];
int deg[N];

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        edgeFrom[i] = a;
        edgeTo[i] = b;
        V[a].push_back({b, i});
        V[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }
    
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] < k) {
            Q.push(i);
        }
    }
    
    vector<int> answers;
    int ans = n;
    for (int i = m; i >= 1; i--) {
        while (!Q.empty()) {
            int w = Q.front();
            removed[w] = true;
            Q.pop();
            ans--;
            for (auto p : V[w]) {
                int u = p.first;
                int id = p.second;
                if (id > i) {
                    continue;
                }
                deg[u]--;
                if (deg[u] == k - 1) {
                    Q.push(u);
                }
            }
        }
        answers.push_back(ans);
        if (removed[edgeFrom[i]] || removed[edgeTo[i]]) {
            continue;
        }
        deg[edgeFrom[i]]--;
        if (deg[edgeFrom[i]] == k - 1) {
            Q.push(edgeFrom[i]);
        }
        deg[edgeTo[i]]--;
        if (deg[edgeTo[i]] == k - 1) {
            Q.push(edgeTo[i]);
        }
    }
    
    reverse(answers.begin(), answers.end());
    for (int w : answers) {
        printf("%d\n", w);
    }
    
    return 0;
}