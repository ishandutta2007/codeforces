#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>
#include <vector>

using namespace std;

const int maxn = 300100;

int n, m, a[maxn], p[maxn];
int S[maxn], sze;
int C[maxn][2];
vector<int> Q[maxn];

void dfs(int v, int l = 0, int r = n) {
    if (C[v][0] != -1) dfs(C[v][0], l, v);
    if (C[v][1] != -1) dfs(C[v][1], v + 1, r);

    if (l) Q[l - 1].push_back(p[v] + m);
    if (v) Q[v - 1].push_back(p[v]);
    Q[v + 1].push_back(p[v + 1] + m);
    Q[r].push_back(p[v + 1]);

    if (C[v][0] == -1 || C[v][1] == -1) return;
    if (v - l < r - v) {
        for (int i = l; i < v; i++) {
            int x = (m - (p[v] - p[i] + m) % m + p[v + 1]) % m;
            Q[v + 1].push_back(x + m);
            Q[r].push_back(x);
        }
    } else {
        for (int i = v + 1; i < r; i++) {
            int x = (p[i + 1] - p[v + 1] + m + p[v]) % m;
            if (l) Q[l - 1].push_back(x + m);
            if (v) Q[v - 1].push_back(x);
        }
    }
}

int F[1000100];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = (p[i] + a[i]) % m;
    }
    a[n] = (1e9) + 5;

    memset(C, -1, sizeof(C));
    for (int i = 0; i <= n; i++) {
        int x = -1;
        while (sze && a[S[sze - 1]] < a[i]) {
            if (sze > 1) C[S[sze - 2]][1] = S[sze - 1];
            x = S[sze - 1];
            sze--;
        }

        if (x != -1) C[i][0] = x;
        S[sze++] = i;
    }

    //for (int i = 0; i < n; i++) cout << a[i] << ' ' << a[C[i][0]] << ' ' << a[C[i][1]] << endl;

    dfs(C[n][0]);

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        F[p[i]]++;
        for (int j : Q[i]) {
            if (j >= m) ans -= F[j - m];
            else ans += F[j];
        }
    }

    cout << ans << '\n';
}