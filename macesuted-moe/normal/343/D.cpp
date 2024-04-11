/**
 * @file C.cpp
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

#define maxn 500005

template <typename T>
class SegmentTree {
   private:
    T sum[maxn << 2], lazy[maxn << 2];

    inline void pushDown(int p) {
        if (lazy[p] == -1) return;
        lazy[p << 1] = lazy[p << 1 | 1] = sum[p << 1] = sum[p << 1 | 1] = lazy[p];
        lazy[p] = -1;
        return;
    }
    void _set(int p, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) return sum[p] = lazy[p] = val, void();
        pushDown(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) _set(p << 1, l, mid, ql, qr, val);
        if (qr > mid) _set(p << 1 | 1, mid + 1, r, ql, qr, val);
        sum[p] = max(sum[p << 1], sum[p << 1 | 1]);
        return;
    }
    T _get(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return sum[p];
        pushDown(p);
        int mid = (l + r) >> 1;
        T ans = 0;
        if (ql <= mid) ans = max(ans, _get(p << 1, l, mid, ql, qr));
        if (qr > mid) ans = max(ans, _get(p << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }

   public:
    SegmentTree(void) { memset(lazy, -1, sizeof(lazy)); }
    inline void set(int n, int ql, int qr, T val) { return _set(1, 1, n, ql, qr, val); }
    inline T get(int n, int ql, int qr) { return _get(1, 1, n, ql, qr); }
};

vector<vector<int> > graph;
int dfni[maxn], dfno[maxn], opt[maxn];

int tim = 0;
void dfs(int p, int fath) {
    dfni[p] = ++tim;
    for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (*i != fath) dfs(*i, p);
    dfno[p] = tim;
    return;
}

SegmentTree<int> tree[2];

int main() {
    int n = read<int>();
    graph.resize(n + 1);
    for (register int i = 1, from, to; i < n; i++) {
        from = read<int>(), to = read<int>();
        graph[from].push_back(to), graph[to].push_back(from);
    }

    dfs(1, -1);

    for (register int q = read<int>(), i = 1; i <= q; i++) {
        opt[i] = read<int>();
        register int x = read<int>();
        if (opt[i] == 1)
            tree[0].set(n, dfni[x], dfno[x], i);
        else if (opt[i] == 2)
            tree[1].set(n, dfni[x], dfni[x], i);
        else
            printf("%d\n", tree[0].get(n, dfni[x], dfni[x]) > tree[1].get(n, dfni[x], dfno[x]));
    }
    return 0;
}

/*
Input:
5
1 2
5 1
2 3
4 2
12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5
Output:
0
0
0
1
0
1
0
1
*/