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

pii far(int p, int f) {
    pii ret = (pii){0, p};
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != f) ret = max(ret, far(*i, p));
    return (pii){ret.first + 1, ret.second};
}
int dis(int p, int to, int fath) {
    if (p == to) return 0;
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fath) {
            int ret = dis(*i, to, p);
            if (ret != -1) return ret + 1;
        }
    return -1;
}

int main() {
    for (register int T = read<int>(); T; T--) {
        int n = read<int>(), a = read<int>(), b = read<int>(), da = read<int>(), db = read<int>();
        graph.resize(n + 1);
        for (register int i = 1, from, to; i < n; i++) {
            from = read<int>(), to = read<int>();
            graph[from].push_back(to), graph[to].push_back(from);
        }

        if (db > (da << 1) && far(far(1, -1).second, -1).first - 1 > (da << 1) && dis(a, b, -1) > da)
            puts("Bob");
        else
            puts("Alice");

        graph.clear();
    }
    return 0;
}

/*
Input:
4
4 3 2 1 2
1 2
1 3
1 4
6 6 1 2 5
1 2
6 5
2 3
3 4
4 5
9 3 9 2 5
1 2
1 6
1 9
1 3
9 5
7 9
4 8
4 3
11 8 11 3 3
1 2
11 9
4 9
6 5
2 10
3 2
5 9
8 3
7 4
7 10
Output:
Alice
Bob
Alice
Alice
*/