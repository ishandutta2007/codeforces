#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1505;
const int Maxm = Maxn * Maxn;

struct node {
    int en;
    vector <int> cols;
};

int n, q;
int B[Maxn][Maxn];
vector <node> C[Maxn][Maxn];
ll res[Maxn];
node tmp;
bool G[Maxm];
int ing[Maxm], glen;

void Add(vector <int> &V, const vector <int> &toadd)
{
    for (auto a: toadd)
        if (!G[a]) {
            G[a] = true;
            V.push_back(a);
            ing[glen++] = a;
        }
}

void Solve(int i, int j)
{
    tmp.en = 1;
    tmp.cols.clear();
    tmp.cols.push_back(B[i][j]);
    C[i][j].push_back(tmp);
    if (i == n - 1 || j == n - 1) { res[1]++; return; }
    for (int l = 0; l < glen; l++)
        G[ing[l]] = false;
    glen = 0;
    G[B[i][j]] = true;
    ing[glen++] = B[i][j];
    int a = 0, b = 0, c = 0;
    int cur = 1;
    while (true) {
        tmp.cols.clear();
        int mn = Maxn;
        while (a < C[i][j + 1].size() && C[i][j + 1][a].en < cur) a++;
        if (a >= C[i][j + 1].size()) break;
        mn = min(mn, C[i][j + 1][a].en);
        Add(tmp.cols, C[i][j + 1][a].cols);
        if (glen > q) break;
        while (b < C[i + 1][j].size() && C[i + 1][j][b].en < cur) b++;
        if (b >= C[i + 1][j].size()) break;
        mn = min(mn, C[i + 1][j][b].en);
        Add(tmp.cols, C[i + 1][j][b].cols);
        if (glen > q) break;
        while (c < C[i + 1][j + 1].size() && C[i + 1][j + 1][c].en < cur) c++;
        if (c >= C[i + 1][j + 1].size()) break;
        mn = min(mn, C[i + 1][j + 1][c].en);
        Add(tmp.cols, C[i + 1][j + 1][c].cols);
        if (glen > q) break;
        if (tmp.cols.empty()) C[i][j].back().en = mn + 1;
        else {
            tmp.en = mn + 1;
            C[i][j].push_back(tmp);
        }
        cur = mn + 1;
    }
    res[C[i][j].back().en]++;
}

void Solve(int diag)
{
    for (int i = max(0, diag - (n - 1)); i < n && i <= diag; i++) {
        int j = diag - i;
        Solve(i, j);
    }
}

void Clear(int diag)
{
    for (int i = max(0, diag - (n - 1)); i < n && i <= diag; i++) {
        int j = diag - i;
        C[i][j].clear();
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    for (int i = 2 * n - 2; i >= 0; i--) {
        if (i + 3 <= 2 * n - 2) Clear(i + 3);
        Solve(i); 
    }
    for (int i = n - 1; i > 0; i--)
        res[i] += res[i + 1];
    for (int i = 1; i <= n; i++)
        printf("%I64d\n", res[i]);
    return 0;
}