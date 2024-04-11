#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000000;

char tmp[Maxn];
int T;
int n;
vector <string> B[Maxn];
bool tk[Maxn];
int dist[Maxn][Maxn];

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

bool Check(int a, int b, int c)
{
    if (a > b) swap(a, b);
    return B[a][b - a - 1][c] == '1';
}

void Construct(int v, int p)
{
    for (int i = 0; i < n; i++) if (!tk[i])
        if (Check(i, p, v)) {
            tk[i] = true;
            dist[v][i] = dist[i][v] = 1;
            Construct(i, v);
        }
}

bool Solve(int v)
{
    fill(tk, tk + n, false);
    tk[0] = tk[v] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i != j) * Inf;
    dist[0][v] = dist[v][0] = 1;
    Construct(0, v);
    Construct(v, 0);
    for (int i = 0; i < n; i++)
        if (!tk[i]) return false;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < B[i].size(); j++)
            for (int k = 0; k < n; k++)
                if (int(dist[i][k] == dist[i + 1 + j][k]) != int(B[i][j][k] - '0'))
                    return false;
    return true;
}

void Print()
{
    printf("Yes\n");
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) if (dist[i][j] == 1)
            printf("%d %d\n", i + 1, j + 1);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            B[i].resize(n - i - 1);
            for (int j = 0; j < B[i].size(); j++)
                Read(B[i][j]);
        }
        bool found = false;
        for (int i = 1; i < n; i++)
            if (Solve(i)) {
                Print();
                found = true;
                break;
            }
        if (!found) printf("No\n");
    }
    return 0;
}