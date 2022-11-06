#include <bits/stdc++.h>

using namespace std;

const int N = 200005, INF = 2e9;

int n, m;
int par[N], depth[N], ans[N], myBegin[N], subSize[N], preOrder[N], preTime;
vector<int> V[N], path[N];
pair<int, int> query[N];
int arr[N];

class IntervalTree {
public:
    int BASE;
    vector<int> path;
    vector<pair<int, int> > tree;
    vector<int> lazy;

    pair<int, int> better(const pair<int, int> &A, const pair<int, int> &B) {
        return A.first + 2 * depth[A.second] >= B.first + 2 * depth[B.second] ? A : B;
    }

    IntervalTree(vector<int> v) {
        path = v;
        BASE = 1;
        while (BASE < v.size()) {
            BASE *= 2;
        }
        tree.resize(2 * BASE + 1);
        lazy.resize(2 * BASE + 1, -INF - 1);
        for (int i = 0; i < v.size(); i++) {
            tree[i + BASE] = make_pair(-INF, v[i]);
        }
        for (int i = BASE - 1; i >= 1; i--) {
            tree[i] = better(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void propagate(int w, int y) {
        if (lazy[w] != -INF - 1) {
            tree[w] = make_pair(lazy[w], path[y]);
            if (w < BASE) {
                lazy[2 * w] = lazy[w];
                lazy[2 * w + 1] = lazy[w];
            }
            lazy[w] = -INF - 1;
        }
    }

    void insert(int w, int posa, int posb, int x, int y, int value) {
        if (posa > posb) {
            return;
        }
        propagate(w, y);
        if (posa <= x && y <= posb) {
            tree[w] = {value, path[y]};
            if (x < y) {
                lazy[2 * w] = value;
                lazy[2 * w + 1] = value;
            }
            return;
        }
        int mid = (x + y) / 2;
        if (x <= posb && posa <= mid) {
            insert(2 * w, posa, posb, x, mid, value);
            tree[w] = better(tree[w], tree[2 * w]);
        }
        if (mid + 1 <= posb && posa <= y) {
            insert(2 * w + 1, posa, posb, mid + 1, y, value);
            tree[w] = better(tree[w], tree[2 * w + 1]);
        }
    }

    pair<int, int> query(int w, int posa, int posb, int x, int y, int value) {
        propagate(w, y);
        if (posa > posb || tree[w].first + 2 * depth[tree[w].second] <= value) {
            return {-INF - 1, -1};
        }

        if (w >= BASE) {
            if (tree[w].first + 2 * depth[tree[w].second] > value) {
                return tree[w];
            } else {
                return {-INF - 1, -1};
            }
        }

        int mid = (x + y) / 2;
        if (mid + 1 <= posb && posa <= y) {
            pair<int, int> r = query(2 * w + 1, posa, posb, mid + 1, y, value);
            if (r.second != -1) {
                return r;
            }
        }
        if (x <= posb && posa <= mid) {
            pair<int, int> r = query(2 * w, posa, posb, x, mid, value);
            return r;
        } else {
            return {-INF - 1, -1};
        }
    }
};

IntervalTree* intTree[N];

bool cmp(int a, int b) {
    if (depth[query[a].first] + query[a].second == depth[query[b].first] + query[b].second) {
        return query[a].first < query[b].first;
    }
    return depth[query[a].first] + query[a].second < depth[query[b].first] + query[b].second;
}

bool cmp2(int a, int b) {
    return subSize[a] < subSize[b];
}

void DFS(int w) {
    subSize[w] = 1;
    preOrder[w] = ++preTime;
    sort(V[w].begin(), V[w].end());
    for (int i = 0; i < V[w].size(); i++) {
        depth[V[w][i]] = depth[w] + 1;
        DFS(V[w][i]);
        subSize[w] += subSize[V[w][i]];
    }
    sort(V[w].begin(), V[w].end(), cmp2);
}

void DFSHLD(int w, int b) {
    path[b].push_back(w);
    myBegin[w] = b;
    if (!V[w].empty()) {
        DFSHLD(V[w].back(), b);
    }
    for (int i = 0; i < (int)V[w].size() - 1; i++) {
        DFSHLD(V[w][i], V[w][i]);
    }
}

int findMax(int from, int t) {
    int w = from;
    while (true) {
        int HLDpath = myBegin[w];
        pair<int, int> q = intTree[HLDpath]->query(1, 0, depth[w] - depth[HLDpath], 0, intTree[HLDpath]->BASE - 1, t);
        if (q.second != -1) {
            return q.second;
        }
        w = par[HLDpath];
    }
    exit(-1);
}

void insert(int from, int to, int t) {
    int w = from;
    while (true) {
        int HLDpath = myBegin[w];
        if (depth[HLDpath] <= depth[to]) {
            intTree[HLDpath]->insert(1, depth[to] - depth[HLDpath] + 1, depth[w] - depth[HLDpath], 0, intTree[HLDpath]->BASE - 1, t);
            break;
        } else {
            intTree[HLDpath]->insert(1, 0, depth[w] - depth[HLDpath], 0, intTree[HLDpath]->BASE - 1, t);
            w = par[HLDpath];
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &par[i]);
        V[par[i]].push_back(i);
    }

    DFS(0);
    DFSHLD(0, 0);

    for (int i = 0; i <= n; i++) {
        if (!path[i].empty()) {
            intTree[i] = new IntervalTree(path[i]);
        }
    }
    intTree[0]->insert(1, 0, 0, 0, intTree[0]->BASE - 1, INF);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &query[i].first, &query[i].second);
        arr[i] = i;
    }

    sort(arr + 1, arr + 1 + m, cmp);

    for (int i = 1; i <= m; i++) {
        int w = query[arr[i]].first;
        int t = query[arr[i]].second;
        int res = findMax(w, t + depth[w]);
        ans[arr[i]] = t + 2 * (depth[w] - depth[res]);
        insert(w, res, t + depth[w] - 2 * depth[res]);
    }

    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}