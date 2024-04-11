#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
long long k;
int h[N][N];
vector<pair<int, pair<int, int> > > heights;
bool vis[N][N];
pair<int, int> rep[N][N];
int size[N][N];
bool added[N][N];
int cur;

pair<int, int> find(pair<int, int> w) {
    if (rep[w.first][w.second] == w) {
        return w;
    } else {
        return rep[w.first][w.second] = find(rep[w.first][w.second]);
    }
}

void Union(int xA, int yA, int xB, int yB) {
    pair<int, int> findA = find({xA, yA});
    pair<int, int> findB = find({xB, yB});
    if (findA == findB) {
        return;
    }
    size[findB.first][findB.second] += size[findA.first][findA.second];
    rep[findA.first][findA.second] = findB;
}

void add(int x, int y) {
    added[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (min(xx, yy) >= 1 && xx <= n && yy <= m && added[xx][yy]) {
            Union(x, y, xx, yy);
        }
    }
}

void printResult(int res) {
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == true) {
                printf("%d ", res);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void DFS(int x, int y, int nec) {
    vis[x][y] = true;
    cur++;
    if (cur == nec) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (min(xx, yy) >= 1 && xx <= n && yy <= m && find({x, y}) == find({xx, yy}) && !vis[xx][yy]) {
            DFS(xx, yy, nec);
            if (cur == nec) {
                return;
            }
        }
    }
}

int main() {

    scanf("%d %d %I64d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &h[i][j]);
            heights.push_back({h[i][j], {i, j}});
            rep[i][j] = {i, j};
            size[i][j] = 1;
        }
    }

    sort(heights.begin(), heights.end());

    for (int i = heights.size() - 1; i >= 0; i--) {
        add(heights[i].second.first, heights[i].second.second);
        if (k % heights[i].first != 0) {
            continue;
        }
        pair<int, int> f = find({heights[i].second.first, heights[i].second.second});
        int mySize = size[f.first][f.second];
        long long nec = k / heights[i].first;
        int maxElements = mySize;
        if (maxElements >= nec) {
            DFS(heights[i].second.first, heights[i].second.second, nec);
            printResult(heights[i].first);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}