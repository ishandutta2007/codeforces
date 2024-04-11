#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

struct dsu {
    vector <int> vec[N];
    int f[N], n;

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (vec[x].size() > vec[y].size()) swap(x, y);
        vec[y].insert(vec[y].end(), vec[x].begin(), vec[x].end());
        vec[x].clear();
        f[x] = y;
    }

    void ini(int _) {
        n = _;
        for (int i = 1; i <= n; i++) f[i] = i, vec[i].resize(1, i);
    }
} f1, f2;

set <int> t[2][2];
int in1[N], in2[N];
int n, m1, m2;

void solve1(int x) {
    x = f1.find(x);
    for (int i = 0; i < (int)f1.vec[x].size(); i++) {
        int id = f1.vec[x][i];
        t[in1[id]][in2[id]].erase(id);
        in1[id] = 1;
        t[in1[id]][in2[id]].insert(id);
    }
}

void solve2(int x) {
    x = f2.find(x);
    for (int i = 0; i < (int)f2.vec[x].size(); i++) {
        int id = f2.vec[x][i];
        t[in1[id]][in2[id]].erase(id);
        in2[id] = 1;
        t[in1[id]][in2[id]].insert(id);
    }
}

int main() {
    read(n); read(m1); read(m2);
    f1.ini(n); f2.ini(n);
    for (int i = 1; i <= m1; i++) {
        int u, v;
        read(u); read(v);
        f1.merge(u, v);
    }
    for (int i = 1; i <= m2; i++) {
        int u, v;
        read(u); read(v);
        f2.merge(u, v);
    }
    int id = f1.find(1);
    for (int i = 0; i < (int)f1.vec[id].size(); i++) in1[f1.vec[id][i]] = 1;
    id = f2.find(1);
    for (int i = 0; i < (int)f2.vec[id].size(); i++) in2[f2.vec[id][i]] = 1;
    for (int i = 1; i <= n; i++) t[in1[i]][in2[i]].insert(i);
    print(n - 1 - max(m1, m2), '\n');
    for (int _ = 1; _ <= n - 1 - max(m1, m2); _++) {
        if (t[0][0].size() && t[1][1].size()) {
            int x = *t[0][0].begin();
            print(x, ' '); print(*t[1][1].begin(), '\n');
            solve1(x); solve2(x);
        } else {
            int x = *t[0][1].begin(), y = *t[1][0].begin();
            print(x, ' '); print(y, '\n');
            solve1(x); solve2(y);
        }
    }
    return 0;
}