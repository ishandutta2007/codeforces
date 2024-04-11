/**
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

#define maxn 2000005
#define oppo(x) ((x + n) > (n << 1) ? (x - n) : (x + n))

vector<vector<int> > graph;
stack<int> st;
bool inStack[maxn];
int dfn[maxn], low[maxn], bel[maxn], deg[maxn];
int blockCnt = 0;

int tim = 0;
void tarjan(int p) {
    dfn[p] = low[p] = ++tim;
    st.push(p), inStack[p] = true;
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (!dfn[*i]) {
            tarjan(*i);
            low[p] = min(low[p], low[*i]);
        } else if (inStack[*i])
            low[p] = min(low[p], dfn[*i]);
    if (dfn[p] == low[p]) {
        blockCnt++;
        while (st.top() != p) bel[st.top()] = blockCnt, inStack[st.top()] = false, st.pop();
        bel[st.top()] = blockCnt, inStack[st.top()] = false, st.pop();
    }
    return;
}

int main() {
    int n = read<int>(), m = read<int>();
    graph.resize((n << 1) + 1);
    int lastFrom, lastTo, lastDist;
    for (register int i = 1, from, to, dist; i <= m; i++) {
        lastFrom = from = read<int>(), lastTo = to = read<int>(), lastDist = dist = read<int>();
        if (dist == 0)
            graph[from].push_back(oppo(to)), graph[oppo(from)].push_back(to),
                graph[to].push_back(oppo(from)), graph[oppo(to)].push_back(from);
        else
            graph[from].push_back(to), graph[oppo(from)].push_back(oppo(to)),
                graph[to].push_back(from), graph[oppo(to)].push_back(oppo(from));
    }
    for (register int i = 1; i <= (n << 1); i++)
        if (!dfn[i]) tarjan(i);
    // for (register int i = 1; i <= (n << 1); i++) {
    //     printf("%d:", i);
    //     for (vector<int>::iterator j = graph[i].begin(); j != graph[i].end(); j++) printf("%d ", *j);
    //     puts("");
    // }
    // for (register int i = 1; i <= (n << 1); i++) printf("%d ", bel[i]);
    // puts("");
    for (register int i = 1; i <= n; i++)
        if (bel[i] == bel[i + n]) return puts("Impossible"), 0;
    static set<int> S;
    S.clear();
    for (register int i = 1; i <= n; i++)
        if (bel[i] > bel[i + n]) S.insert(i);
    if ((lastDist ^ (S.find(lastFrom) != S.end()) ^ (S.find(lastTo) != S.end())) == 0) {
        printf("%d\n", n - S.size());
        for (register int i = 1; i <= n; i++)
            if (S.find(i) == S.end()) printf("%d ", i);
    } else {
        printf("%d\n", S.size());
        for (register int i = 1; i <= n; i++)
            if (S.find(i) != S.end()) printf("%d ", i);
    }
    puts("");
    return 0;
}