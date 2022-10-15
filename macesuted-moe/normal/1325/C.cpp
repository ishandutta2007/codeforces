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
int deg[maxn];

int main() {
    int n = read<int>();
    for (register int i = 1, from, to; i < n; i++) {
        from = read<int>(), to = read<int>();
        graph.push_back((pii){from, to});
        deg[from]++, deg[to]++;
    }
    int spe = -1;
    for (register int i = 1; i <= n; i++)
        if (deg[i] >= 3) {
            spe = i;
            break;
        }
    int commonCnt = spe == -1 ? 0 : 3;
    int speCnt = 0;
    for (register int i = 0; i < n - 1; i++)
        if ((graph[i].first == spe || graph[i].second == spe) && speCnt < 3)
            printf("%d\n", speCnt++);
        else
            printf("%d\n", commonCnt++);
    return 0;
}