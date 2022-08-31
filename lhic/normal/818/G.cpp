#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
int a[3100];

struct edge {
    int a, b, c, f, w;
};

vector<edge> ed;
vector<int> eds[120000];
int dd[120000];
int go[120000];
int en[120000];
queue<int> qu;
const int INF = 1200000;
int s, t;
int nx[120000];
int nx2[10];

void add_edge(int a, int b, int c, int w) {
    edge x;
    x.a = a, x.b = b, x.c = c, x.w = w, x.f = 0;
    eds[a].push_back(ed.size());
    ed.push_back(x);
    swap(x.a, x.b);
    x.c = 0;
    x.w = -w;
    eds[b].push_back(ed.size());
    ed.push_back(x);
}

int flow(int k) {
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        fill(dd, dd + t + 1, INF);
        fill(en, en + t + 1, 0);
        dd[s] = 0;
        en[s] = 1;
        qu.push(s);
        while (!qu.empty()) {
            int x = qu.front();
            qu.pop();
            en[x] = 0;
            for (int e: eds[x]) {
                int u = ed[e].b;
                if (ed[e].c > ed[e].f && dd[u] > dd[x] + ed[e].w) {
                    dd[u] = dd[x] + ed[e].w;
                    go[u] = e;
                    if (!en[u]) {
                        en[u] = 1;
                        qu.push(u);
                    }
                }
            }
        }
        ans += dd[t];
        int now = t;
        while (now != s) {
            int e = go[now];
            ++ed[e].f;
            --ed[e ^ 1].f;
            now = ed[e].a;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    s = 3 * n;
    t = 3 * n + 1;
    for (int i = n - 1; i >= 0; --i) {
        add_edge(i * 3, i * 3 + 1, n, 0);
        add_edge(i * 3 + 1, i * 3 + 2, 1, -1);
        int x = a[i];
        int y = a[i] % 7;
        if (nx[x]) {
            add_edge(i * 3 + 1, nx[x] * 3 + 1, n, 0);
        }
        if (nx2[y]) {
            add_edge(i * 3, nx2[y] * 3, n, 0);
            add_edge(i * 3 + 2, nx2[y] * 3, n, 0);
        }
        if (nx[x + 1]) {
            add_edge(i * 3 + 2, nx[x + 1] * 3 + 1, n, 0);
        }
        if (nx[x - 1]) {
            add_edge(i * 3 + 2, nx[x - 1] * 3 + 1, n, 0);
        }
        nx[x] = i;
        nx2[y] = i;
        add_edge(s, i * 3 + 1, n, 0);
        add_edge(i * 3 + 2, t, n, 0);
    }
    int ans = flow(4);
    cout << -ans << "\n";
    return 0;
}