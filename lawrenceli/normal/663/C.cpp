#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cstring>
#include <cassert>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 100100;
const int inf = 1e9;

int n, m;
vector<pii> adj[maxn];

int col, ccnt;
int V[maxn], VS;
int U[maxn], US;

int C[maxn];
bool good;

void dfs(int v, int c) {
    V[VS++] = v;
    if (c) ccnt++;
    C[v] = c;
    for (pii p : adj[v]) {
        if (C[p.A] >= 0) {
            if ((c ^ C[p.A] ^ p.B) != col)
                good = 0;
        } else dfs(p.A, c ^ p.B ^ col);
    }
}

void go() {
    memset(C, -1, sizeof(C));
    VS = ccnt = 0;
    for (int i = 0; i < n; i++)
        if (C[i] == -1) {
            int k = VS, oc = ccnt;
            good = 1;
            dfs(i, 0);
            int a = good ? ccnt - oc : inf;
            for (int j = k; j < VS; j++) C[V[j]] = -1;
            VS = k, ccnt = oc;
            good = 1;
            dfs(i, 1);
            int b = good ? ccnt - oc : inf;
            if (a == inf && b == inf) {
                VS = -1;
                return;
            }
            if (a < b) {
                for (int j = k; j < VS; j++) C[V[j]] = -1;
                VS = k, ccnt = oc;
                good = 1;
                dfs(i, 0);
            }
        }

    VS = 0;
    for (int i = 0; i < n; i++)
        if (C[i])
            V[VS++] = i;

    assert(VS == ccnt);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        a--, b--;
        int d = c == 'B';
        adj[a].push_back(pii(b, d));
        adj[b].push_back(pii(a, d));
    }

    go();
    col = 1;
    for (int i = 0; i < VS; i++) U[i] = V[i];
    US = VS;
    go();

    if (VS != -1 && (US == -1 || VS < US)) {
        for (int i = 0; i < VS; i++) U[i] = V[i];
        US = VS;
    }

    cout << US << '\n';
    for (int i = 0; i < US; i++) cout << U[i] + 1 << ' ';
}