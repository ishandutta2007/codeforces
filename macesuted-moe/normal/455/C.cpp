/**
 * @file B.cpp
 * @author Macesuted
 * @date 2021-02-05
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

vector<vector<int> > graph;
int fa[maxn], len[maxn];

inline int getfa(int p) { return fa[p] == p ? p : fa[p] = getfa(fa[p]); }

void floodFill(int p, int root) {
    fa[p] = root;
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (!fa[*i]) floodFill(*i, root);
    return;
}
pii far(int p, int f) {
    pii ret = (pii){0, p};
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != f) ret = max(ret, far(*i, p));
    return (pii){ret.first + 1, ret.second};
}

int main() {
    int n = read<int>(), m = read<int>(), q = read<int>();
    graph.resize(n + 1);
    for (register int i = 1, from, to; i <= m; i++) {
        from = read<int>(), to = read<int>();
        graph[from].push_back(to), graph[to].push_back(from);
    }

    for (register int i = 1; i <= n; i++)
        if (!fa[i]) floodFill(i, i), len[i] = far(far(i, -1).second, -1).first - 1;

    while (q--) {
        register int opt = read<int>(), x = read<int>();
        if (opt == 1)
            printf("%d\n", len[getfa(x)]);
        else {
            register int y = read<int>();
            x = getfa(x), y = getfa(y);
            if (x == y) continue;
            len[x] = max(len[y], max(len[x], (len[x] >> 1) + (len[x] & 1) + (len[y] >> 1) + (len[y] & 1) + 1));
            fa[y] = x;
        }
    }
    return 0;
}

/*
Input:
6 0 6
2 1 2
2 3 4
2 5 6
2 3 2
2 5 3
1 1
Output:
4
*/