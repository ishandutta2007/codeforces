#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int mod = 998244353;

int T;
int n;
vector <int> neigh[Maxn];
int res[Maxn];
int root;

void Print()
{
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
}

ii Solve(int v, int p, int val)
{
    int ch = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ii got = Solve(u, v, val);
        if (got.first == 0) return ii(0, 0);
        ch += got.second;
    }
    if (ch % val == 0) return ii(1, 1);
    if ((ch + 1) % val == 0) return ii(1, 0);
    return ii(0, 0);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            res[i] = 0;
        }
        res[1] = 1;
        for (int i = 0; i < n - 1; i++) {
            res[1] = 2ll * res[1] % mod;
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        if (n == 2) { Print(); continue; }
        root = 1;
        while (neigh[root].size() == 1) root++;
        int X;
        for (int i = 1; i <= n; i++) if (neigh[i].size() > 1) {
            int bad = 0;
            for (int j = 0; j < neigh[i].size(); j++) {
                int u = neigh[i][j];
                bad += neigh[u].size() != 1;
            }
            if (bad <= 1) { X = int(neigh[i].size()) - 1; break; }
        }
        for (int i = n; i >= 1; i--) {
            if (i > 1 && (X % i == 0 || (X + 1) % i == 0)) {
                ii got = Solve(root, 0, i);
                if (got.second == 1) res[i] = got.first; 
            }
            for (int j = i + i; j <= n; j += i)
                res[i] = (res[i] - res[j] + mod) % mod;
        }
        Print();
    }
    return 0;
}