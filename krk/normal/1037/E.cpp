#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m, k;
set <int> S[Maxn];
int X[Maxn], Y[Maxn];
int cur;
int res[Maxn];
queue <int> Q;

void Process()
{
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(); cur--;
        for (set <int>::iterator it = S[v].begin(); it != S[v].end(); ) {
            int u = *it;
            if (S[u].size() == k) Q.push(u);
            S[u].erase(v); S[v].erase(it++);
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        S[X[i]].insert(Y[i]);
        S[Y[i]].insert(X[i]);
    }
    cur = n;
    for (int i = 1; i <= n; i++)
        if (S[i].size() < k) Q.push(i);
    Process();
    res[m - 1] = cur;
    for (int i = m - 1; i > 0; i--) {
        if (S[X[i]].size() >= k && S[Y[i]].size() >= k) {
            if (S[X[i]].size() == k) Q.push(X[i]);
            if (S[Y[i]].size() == k) Q.push(Y[i]);
            S[X[i]].erase(Y[i]);
            S[Y[i]].erase(X[i]);
        }
        Process();
        res[i - 1] = cur;
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", res[i]);
    return 0;
}