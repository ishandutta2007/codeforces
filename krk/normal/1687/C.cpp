#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m;
int a[Maxn];
int b[Maxn];
ll A[Maxn];
set <int> S;
vector <int> neigh[Maxn];

void Add(vector <int> &Q, int l, int r)
{
    if (l > r) swap(l, r);
    for (auto it = S.lower_bound(l); it != S.end() && *it <= r; ) {
        Q.push_back(*it);
        A[*it] = 0;
        S.erase(it++);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        S.clear();
        for (int i = 0; i <= n; i++)
            neigh[i].clear();
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++)
            A[i] = A[i - 1] + b[i] - a[i];
        vector <int> Q;
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            a--;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        for (int i = 0; i <= n; i++)
            if (A[i] == 0) Q.push_back(i);
            else S.insert(i);
        for (int i = 0; i < Q.size(); i++) {
            int v = Q[i];
            for (int j = 0; j < neigh[v].size(); j++) {
                int oth = neigh[v][j];
                if (A[oth] == 0)
                    Add(Q, v, oth);
            }
        }
        printf("%s\n", Q.size() == n + 1? "YES": "NO");
    }
    return 0;
}