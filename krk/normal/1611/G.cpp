#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char tmp[Maxn];
int T;
int n, m;
string B[Maxn];
vector <int> V[Maxn];
int to;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void Remove(int col, int row)
{
    for (int j = col; j <= to && row < n; j++) {
        if (V[j].empty() || V[j].back() < row) { row++; continue; }
        int nrow = V[j].back();
        while (!V[j].empty() && V[j].back() >= row) V[j].pop_back();
        row = nrow + 1;
    }
}

int Solve(int nd)
{
    for (int j = 0; j <= to; j++)
        V[j].clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if ((j + i) % 2 == nd && B[i][j] == '1')
            V[(i + j) / 2].push_back(i);
    int res = 0;
    for (int j = 0; j <= to; j++) if (!V[j].empty()) {
        res++;
        Remove(j, 0);
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        to = (n + m - 2) / 2;
        for (int i = 0; i < n; i++)
            Read(B[i]);
        printf("%d\n", Solve(0) + Solve(1));
    }
    return 0;
}