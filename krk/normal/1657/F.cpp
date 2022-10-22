#include <bits/stdc++.h>
using namespace std;

const int Maxm = 10000000;
const int Maxn = 400005;
const int Maxl = 26;

char tmp[Maxn];
int n, q;
vector <int> tneigh[Maxn];
int L[Maxn], P[Maxn];
vector <int> has[Maxn][Maxl];
int id[Maxn][Maxl];
int slen;
char res[Maxn];
vector <int> neigh[Maxm];
int S[Maxm];
int stlen;
int comp, incomp[Maxm];
int cur, tim[Maxm], low[Maxm];
bool onStack[Maxm];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int Not(int v) { return v % 2? v - 1: v + 1; }

void createNode() { slen += 2; }

int getLst() { return slen - 2; }

void buildTree(int v)
{
    for (int i = 0; i < tneigh[v].size(); i++) {
        int u = tneigh[v][i];
        if (u == P[v]) continue;
        L[u] = L[v] + 1; P[u] = v;
        buildTree(u);
    }
}

void Add(int x, int y, const string &s, int wh)
{
    int lef = 0, rig = int(s.length()) - 1;
    while (x != y)
        if (L[x] >= L[y]) {
            int let = s[lef] - 'a'; lef++;
            has[x][let].push_back(wh);
            x = P[x];
        } else {
            int let = s[rig] - 'a'; rig--;
            has[y][let].push_back(wh);
            y = P[y];
        }
    int let = s[lef] - 'a';
    has[x][let].push_back(wh);
}

void SCC(int v)
{
    cur++;
    tim[v] = low[v] = cur;
    S[stlen++] = v;
    onStack[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (!tim[u]) {
            SCC(u);
            low[v] = min(low[v], low[u]);
        } else if (onStack[u])
            low[v] = min(low[v], tim[u]);
    }
    if (tim[v] == low[v]) {
        comp++;
        int u;
        do {
            u = S[--stlen];
            onStack[u] = false;
            incomp[u] = comp;
        } while (u != v);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        tneigh[a].push_back(b);
        tneigh[b].push_back(a);
    }
    buildTree(1);
    for (int i = 0; i < q; i++) {
        int x, y; scanf("%d %d", &x, &y);
        string s; Read(s);
        createNode();
        int A = getLst();
        Add(x, y, s, A);
        createNode();
        int B = getLst();
        Add(y, x, s, B);
        neigh[Not(A)].push_back(B);
        neigh[Not(B)].push_back(A);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < Maxl; j++) if (!has[i][j].empty()) {
            createNode();
            id[i][j] = getLst();
            for (int z = 0; z < has[i][j].size(); z++) {
                neigh[Not(id[i][j])].push_back(Not(has[i][j][z]));
                neigh[has[i][j][z]].push_back(id[i][j]);
            }
        }
        for (int j = 0; j < Maxl; j++) if (!has[i][j].empty())
            for (int z = 0; z < Maxl; z++) if (j != z && !has[i][z].empty())
                neigh[id[i][j]].push_back(Not(id[i][z]));
    }
    for (int i = 0; i < slen; i++) if (!tim[i])
        SCC(i);
    for (int i = 0; i < slen; i += 2)
        if (incomp[i] == incomp[i + 1]) {
            printf("NO\n");
            return 0;
        }
    for (int i = 1; i <= n; i++) {
        res[i] = 'a';
        for (int j = 0; j < Maxl; j++) if (!has[i][j].empty())
            if (incomp[id[i][j]] < incomp[Not(id[i][j])])
                res[i] = 'a' + j;
    }
    res[n + 1] = '\0';
    printf("YES\n");
    printf("%s\n", res + 1);
    return 0;
}