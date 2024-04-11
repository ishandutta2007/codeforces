/**
 * @file game.cpp
 * @author Macesuted
 * @date 2021-02-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    char c = getchar();
    T f = 1, num = 0;
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 300005

typedef pair<int, int> pii;

vector<vector<int> > graph, tree;
stack<int> st;
bool inStack[maxn];
int dfn[maxn], low[maxn], bel[maxn], deg[maxn];
int blockCnt = 0;

int tim = 0;
void tarjan(int p, int fa) {
    dfn[p] = low[p] = ++tim;
    st.push(p), inStack[p] = true;
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa)
            if (inStack[*i]) {
                low[p] = min(low[p], dfn[*i]);
            } else {
                tarjan(*i, p);
                low[p] = min(low[p], low[*i]);
            }
    if (dfn[p] == low[p]) {
        blockCnt++;
        while (st.top() != p) bel[st.top()] = blockCnt, inStack[st.top()] = false, st.pop();
        bel[st.top()] = blockCnt, inStack[st.top()] = false, st.pop();
    }
    return;
}

pii dfs(int p, int fa) {
    pii ans = (pii){0, p};
    for (vector<int>::iterator i = tree[p].begin(); i != tree[p].end(); i++)
        if (*i != fa) ans = max(ans, dfs(*i, p));
    ans.first++;
    return ans;
}

int main() {
    // freopen("game.in", "r", stdin), freopen("game.out", "w", stdout);
    int n = read<int>(), m = read<int>();
    graph.resize(n + 1);
    for (register int i = 1, from, to; i <= m; i++) {
        from = read<int>(), to = read<int>();
        graph[from].push_back(to), graph[to].push_back(from);
    }
    tarjan(1, -1);
    tree.resize(blockCnt + 1);
    for (register int i = 1; i <= n; i++)
        for (vector<int>::iterator j = graph[i].begin(); j != graph[i].end(); j++)
            if (bel[i] != bel[*j]) tree[bel[i]].push_back(bel[*j]), deg[bel[*j]]++;
    printf("%d\n", dfs(dfs(1, -1).second, -1).first - 1);
    return 0;
}