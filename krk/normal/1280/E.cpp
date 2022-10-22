#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000000;
const int Inf = 1000000000;

int T;
int R;
int slen;
int typ[Maxn];
vector <int> neigh[Maxn];
int dp[Maxn];
ll wrres;
ll res[Maxn];

void createNew()
{
    neigh[slen].clear();
    res[slen] = 0;
    slen++;
}

int getLst() { return slen - 1; }

int constructTree()
{
    char ch; scanf(" %c", &ch);
    createNew();
    int v = getLst();
    if (ch == '*')
        typ[v] = 0;
    else while (true) {
            neigh[v].push_back(constructTree());
            scanf(" %c", &ch);
            if (ch == ')') break;
            if (ch == 'S') typ[v] = 1;
            else typ[v] = 2;
        }
    return v;
}

void Precompute(int v)
{
    if (typ[v] == 0) { dp[v] = 0; return; }
    if (typ[v] == 1) {
        dp[v] = Inf;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            Precompute(u);
            dp[v] = min(dp[v], dp[u]);
        }
    } else {
        dp[v] = 0;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            Precompute(u);
            dp[v] += max(1, dp[u]);
        }
    }
}

void writeRes(int v)
{
    if (typ[v] == 0) { res[v] = wrres; return; }
    if (typ[v] == 1)
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dp[v] == dp[u]) {
                writeRes(u);
                break;
            }
        }
    else for (int i = 0; i < neigh[v].size(); i++)
            writeRes(neigh[v][i]);
}

void Print(int v)
{
    if (typ[v] == 0) { printf(" %I64d", res[v]); return; }
    for (int i = 0; i < neigh[v].size(); i++)
        Print(neigh[v][i]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &R);
        slen = 0;
        constructTree();
        Precompute(0);
        if (dp[0] <= 1) wrres = R;
        else wrres = ll(R) * dp[0];
        writeRes(0);
        printf("REVOLTING");
        Print(0);
        printf("\n");
    }
    return 0;
}