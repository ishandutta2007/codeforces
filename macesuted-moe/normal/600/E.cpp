#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int col[maxn], bucket[maxn];
int siz[maxn], bigSon[maxn];
long long answer[maxn];
bool vis[maxn];
int n;

vector<list<int> > graph;

int read(void) {
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int sum = 0;
    while (isdigit(c)) sum = (sum << 3) + (sum << 1) + (c ^ 48), c = getchar();
    return sum;
}

void dfs(int p, int fa) {
    siz[p] = 1;
    int maxSize = -1;
    for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa) {
            dfs(*i, p);
            siz[p] += siz[*i];
            if (siz[*i] > maxSize) maxSize = siz[*i], bigSon[p] = *i;
        }
    if (maxSize == -1) bigSon[p] = -1;
    return;
}

int more;
long long cnt;

void mark(int p, int fa, int val) {
    bucket[col[p]] += val;
    if (bucket[col[p]] > more)
        more = bucket[col[p]], cnt = col[p];
    else if (bucket[col[p]] == more)
        cnt += col[p];
    for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa && !vis[*i]) mark(*i, p, val);
    return;
}

void DSU(int p, int fa, bool keep) {
    for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fa && *i != bigSon[p]) DSU(*i, p, false), cnt = more = 0;
    if (bigSon[p] != -1) DSU(bigSon[p], p, true), vis[bigSon[p]] = true;
    mark(p, fa, 1);
    answer[p] = cnt;
    if (bigSon[p] != -1) vis[bigSon[p]] = false;
    if (keep == false) mark(p, fa, -1);
    return;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) col[i] = read();
    graph.resize(n + 1);
    for (int i = 1, from, to; i < n; i++) {
        from = read(), to = read();
        graph[from].push_back(to), graph[to].push_back(from);
    }
    dfs(1, 0);
    DSU(1, 0, true);
    for (int i = 1; i <= n; i++) printf("%lld ", answer[i]);
    puts("");
    return 0;
}//awawawa