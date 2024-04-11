#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef pair <ld, int> ldi;
typedef long long ll;

const int Maxn = 305;

int n;
int X[Maxn], Y[Maxn];
int id[Maxn][Maxn];
vector <ldi> seq[Maxn];
ii srt[Maxn];
bool el[Maxn];
int BIT[Maxn][Maxn];
int f[Maxn][Maxn];
ll res;

void Add(int BIT[], int x)
{
    for (int i = x + 1; i <= n; i += i & -i)
        BIT[i]++;
}

int Get(int BIT[], int x)
{
    int res = 0;
    for (int i = x + 1; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int Get(int ind, int from, int to)
{
    if (from < to) return Get(BIT[ind], to - 1) - Get(BIT[ind], from);
    return Get(BIT[ind], n - 1) - Get(BIT[ind], from) + Get(BIT[ind], to - 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        srt[i] = ii(X[i], i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j)
            seq[i].push_back(ldi(atan2(ld(Y[j] - Y[i]), ld(X[j] - X[i])), j));
        sort(seq[i].begin(), seq[i].end());
        for (int j = 0; j < seq[i].size(); j++)
            id[i][seq[i][j].second] = j;
    }
    sort(srt, srt + n);
    for (int i = 0; i < n; i++) {
        int v = srt[i].second;
        for (int b = 0; b < seq[v].size(); b++) {
            int u2 = seq[v][b].second;
            if (el[u2]) continue;
            fill(BIT[u2], BIT[u2] + n + 1, 0);
        }
        for (int a = 0; a < seq[v].size(); a++) {
            int u1 = seq[v][a].second;
            if (el[u1]) continue;
            for (int b = a + 1; b < seq[v].size(); b++) {
                int u2 = seq[v][b].second;
                if (el[u2]) continue;
                f[u1][u2] = Get(u2, id[u2][v], id[u2][u1]);
                Add(BIT[u2], id[u2][u1]);
            }
        }
        for (int a = 0; a < seq[v].size(); a++) {
            int u1 = seq[v][a].second;
            if (el[u1]) continue;
            fill(BIT[u1], BIT[u1] + n + 1, 0);
        }
        for (int b = int(seq[v].size()) - 1; b >= 0; b--) {
            int u2 = seq[v][b].second;
            if (el[u2]) continue;
            for (int a = b - 1; a >= 0; a--) {
                int u1 = seq[v][a].second;
                if (el[u1]) continue;
                res += f[u1][u2] * Get(u1, id[u1][u2], id[u1][v]);
                Add(BIT[u1], id[u1][u2]);
            }
        }
        el[v] = true;
    }
    cout << res << endl;
    return 0;
}