/**
 * @author Macesuted
 * @date 2021-02-03
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

#define maxn 100005

typedef pair<int, int> pii;

vector<pii> graph;

int rest;
inline void addEdge(int from, int to) { return rest--, graph.push_back((pii){from, to}); }

int main() {
    int n = rest = read<int>(), k = read<int>(), d = read<int>();
    if (k >= n || n > 2 && d < 2) return puts("NO"), 0;
    for (register int i = 1; i <= k; i++) addEdge(n - i, n - i + 1);
    for (register int i = 1; i < k && rest > 1; i++) {
        int maxDep = min(i, k - i);
        static queue<pii> que;
        while (!que.empty()) que.pop();
        for (register int j = 2; j < d && rest > 1; j++)
            que.push((pii){rest - 1, maxDep - 1}), addEdge(rest - 1, n - i);
        while (!que.empty() && rest > 1) {
            pii p = que.front();
            que.pop();
            if (p.second == 0) continue;
            for (register int j = 1; j < d && rest > 1; j++)
                que.push((pii){rest - 1, p.second - 1}), addEdge(rest - 1, p.first);
        }
    }
    if (rest > 1)
        puts("NO");
    else {
        puts("YES");
        for (vector<pii>::iterator i = graph.begin(); i != graph.end(); i++) printf("%d %d\n", i->first, i->second);
    }
    return 0;
}