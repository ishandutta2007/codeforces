/**
 * @file lectures.cpp
 * @author Macesuted
 * @date 2020-12-23
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz 1 << 16
char B[bufferSiz], *_S = B, *_T = B;
#define getchar() (_S == _T && (_T = (_S = B) + fread(B, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -f;

        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 300005

int fa[maxn], lef[maxn], rig[maxn], up[maxn], deg[maxn];
bool vis[maxn];
vector<vector<int> > graph[2];
vector<int> output;

int getfa(int k) { return k == fa[k] ? k : fa[k] = getfa(fa[k]); }

int main() {
    // freopen("lectures.in", "r", stdin), freopen("lectures.out", "w", stdout);
    int n = read<int>(), k = read<int>(), root = 0;
    graph[0].resize(n + 1), graph[1].resize(n + 1);
    for (register int i = 1, p; i <= n; i++) (p = read<int>()) ? graph[0][p].push_back(i) : void(root = i);
    for (register int i = 1; i <= n; i++) fa[i] = i;
    for (register int i = 1; i <= k; i++) {
        int l = read<int>(), r = read<int>();
        rig[l] = r, lef[r] = l;
        l = getfa(l), r = getfa(r);
        if (l == r) return puts("0"), 0;
        fa[l] = r;
    }
    for (register int i = 1; i <= n; i++) {
        if (!lef[i]) up[getfa(i)] = i;
        for (vector<int>::iterator j = graph[0][i].begin(); j != graph[0][i].end(); j++)
            if (getfa(i) != getfa(*j)) graph[1][getfa(i)].push_back(getfa(*j)), deg[getfa(*j)]++;
    }
    static queue<int> que;
    que.push(getfa(root));
    output.push_back(114514);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        int t = up[p];
        while (t) output.push_back(t), t = rig[t];
        for (vector<int>::iterator i = graph[1][p].begin(); i != graph[1][p].end(); i++)
            if (!--deg[*i]) que.push(*i);
    }
    if (output.size() != (unsigned)n + 1) return puts("0"), 0;
    vis[root] = true;
    for (register int i = 1; i <= n; i++) {
        if (!vis[output[i]]) return puts("0"), 0;
        for (vector<int>::iterator j = graph[0][output[i]].begin(); j != graph[0][output[i]].end(); j++) vis[*j] = true;
    }
    for (vector<int>::iterator i = output.begin() + 1; i != output.end(); i++) printf("%d ", *i);
    puts("");
    return 0;
}