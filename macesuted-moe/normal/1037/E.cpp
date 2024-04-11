/**
 * @file party.cpp
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

#define maxn 200005

typedef pair<int, int> pii;

vector<pii> edges;
vector<vector<int> > graph;
int deg[maxn];
bool del[maxn];

int n, m, k, rest;

void delNodes(int x = -1) {
    static queue<int> que;
    while (!que.empty()) que.pop();
    if (x == -1) {
        for (register int i = 1; i <= n; i++)
            if (deg[i] < k) que.push(i);
    } else {
        if (del[x] || deg[x] >= k) return;
        que.push(x);
    }
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        if (del[p]) continue;
        del[p] = true, rest--;
        for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
            if (!del[*i]) {
                if (--deg[*i] < k) que.push(*i);
                deg[p]--;
            }
    }
    return;
}

stack<int> answers;

int main() {
    //freopen("party.in", "r", stdin), freopen("party.out", "w", stdout);
    n = rest = read<int>(), m = read<int>(), k = read<int>();
    graph.resize(n + 1);
    for (register int i = 1; i <= m; i++) edges.push_back((pii){read<int>(), read<int>()});
    for (vector<pii>::iterator i = edges.begin(); i != edges.end(); i++)
        graph[i->first].push_back(i->second), graph[i->second].push_back(i->first), deg[i->first]++, deg[i->second]++;
    delNodes();
    for (vector<pii>::reverse_iterator i = edges.rbegin(); i != edges.rend(); i++) {
        answers.push(rest);
        graph[i->first].pop_back(), graph[i->second].pop_back();
        if (del[i->first] || del[i->second]) continue;
        deg[i->first]--, deg[i->second]--;
        delNodes(i->first), delNodes(i->second);
    }
    while (!answers.empty()) printf("%d\n", answers.top()), answers.pop();
    return 0;
}