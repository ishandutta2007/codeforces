#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

bool vis[N];
int size[N];
int prz[N];
int inTime[N], outTime[N], t;
int n, a, b;
vector<int> V[N];
int ansLeft[N], ansRight[N];

void DFS(int w) {
    vis[w] = true;
    size[w] = 1;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            prz[u] = w;
            DFS(u);
            size[w] += size[u];
        }
    }
}

void DFS2(int w) {
    vis[w] = true;
    inTime[w] = ++t;
    size[w] = 1;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS2(u);
            size[w] += size[u];
        }
    }
    outTime[w] = ++t;
}

bool isCentroid(int w) {
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (prz[w] != u && size[u] > n / 2) {
            return false;
        }
    }
    return n - size[w] <= n / 2;
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    DFS(1);

    int cntCentroids = 0;
    int centroid = -1;

    for (int i = 1; i <= n; i++) {
        if (isCentroid(i)) {
            centroid = i;
            cntCentroids++;
        }
    }

    if (cntCentroids == 2) {
        for (int i = 1; i <= n; i++) {
            printf("1 ");
        }
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        vis[i] = size[i] = 0;
    }

    DFS2(centroid);

    vector<pair<int, int> > events;
    for (int i = 1; i <= n; i++) {
        events.push_back({inTime[i], i});
        events.push_back({outTime[i], i});
    }

    sort(events.begin(), events.end());
    set<int> S;
    for (int i = 0; i < events.size(); i++) {
        int _t = events[i].first;
        int w = events[i].second;
        if (_t == inTime[w]) {
            auto it = S.lower_bound(n - size[w] - n / 2);
            if (it == S.end() || *it > n / 2) {
                continue;
            } else {
                ansLeft[w] = true;
            }
        } else {
            S.insert(size[w]);
        }
    }

    S.clear();
    for (int i = events.size() - 1; i >= 0; i--) {
        int _t = events[i].first;
        int w = events[i].second;
        if (_t == outTime[w]) {
            auto it = S.lower_bound(n - size[w] - n / 2);
            if (it == S.end() || *it > n / 2) {
                continue;
            } else {
                ansRight[w] = true;
            }
        } else {
            S.insert(size[w]);
        }
    }

    ansLeft[centroid] = true;
    for (int i = 1; i <= n; i++) {
        printf("%d ", ansLeft[i] | ansRight[i]);
    }

    return 0;
}