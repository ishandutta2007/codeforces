#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a, b;
int forWho[N];
vector<int> V[N];
int depth[N];
vector<int> candidates;
bool failed;
int deg[N];
bool added[N];

int cmp(int a, int b) {
    return depth[a] < depth[b] ? a : b;
}

pair<int, int> better(pair<int, int> &A, pair<int, int> &B) {
    pair<int, int> ret = make_pair(0, 0);
    ret.first = cmp(A.first, B.first);
    if (cmp(A.first, B.first) == A.first) {
        if (B.first != A.first) {
            ret.second = cmp(B.first, A.second);
        } else {
            ret.second = A.second;
        }
    } else {
        if (A.first != B.first) {
            ret.second = cmp(B.second, A.first);
        } else {
            ret.second = B.second;
        }
    }
    return ret;
}

pair<int, int> DFS(int w) {
    pair<int, int> ret = make_pair(forWho[w], 0);
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        depth[u] = depth[w] + 1;
        pair<int, int> retU = DFS(u);
        ret = better(ret, retU);
    }
    if (depth[w] >= depth[ret.first] && (forWho[w] != ret.first || depth[w] >= depth[ret.second])) {
        failed = true;
    }
    if (added[forWho[w]] == false) {
        added[forWho[w]] = true;
    }
    if (added[w]) {
        candidates.push_back(w);
    }
    return ret;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        deg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &forWho[i]);
    }

    depth[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            DFS(i);
            if (failed) {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d\n", candidates.size());
    for (int i = 0; i < candidates.size(); i++) {
        printf("%d\n", candidates[i]);
    }

    return 0;
}