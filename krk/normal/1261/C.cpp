#include <bits/stdc++.h>
using namespace std;

const int Maxl = 1000005;

char tmp[Maxl];
int n, m;
vector <string> B;
vector <vector <int> > S;
vector <vector <int> > C;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int Get(const vector <vector <int> > &S, int r1, int r2, int c1, int c2)
{
    r1 = max(r1, 1);
    r2 = min(r2, n);
    c1 = max(c1, 1);
    c2 = min(c2, m);
    return S[r2][c2] - S[r1 - 1][c2] - S[r2][c1 - 1] + S[r1 - 1][c1 - 1];
}

bool Check(int x)
{
    for (int i = 0; i <= n; i++)
        fill(C[i].begin(), C[i].end(), 0);
    int nd = (2 * x + 1) * (2 * x + 1);
    for (int i = x + 1; i + x <= n; i++)
        for (int j = x + 1; j + x <= m; j++)
            if (Get(S, i - x, i + x, j - x, j + x) == nd)
                C[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            C[i][j] += C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (B[i - 1][j - 1] == 'X' && Get(C, i - x, i + x, j - x, j + x) == 0)
                return false;
    return true;
}

void Mark(int x)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[i][j] = '.';
    int nd = (2 * x + 1) * (2 * x + 1);
    for (int i = x + 1; i + x <= n; i++)
        for (int j = x + 1; j + x <= m; j++)
            if (Get(S, i - x, i + x, j - x, j + x) == nd)
                B[i - 1][j - 1] = 'X';
}

int main()
{
    scanf("%d %d", &n, &m);
    S.resize(n + 1);
    C.resize(n + 1);
    for (int i = 0; i < n; i++) {
        string s; Read(s);
        B.push_back(s);
    }
    for (int i = 0; i <= n; i++) {
        S[i].resize(m + 1, 0);
        C[i].resize(m + 1, 0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            S[i][j] = (B[i - 1][j - 1] == 'X') + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
    int lef = 0, rig = min(n, m);
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) lef = mid + 1;
        else rig = mid - 1;
    }
    int res = lef - 1;
    Mark(res);
    printf("%d\n", res);
    for (int i = 0; i < n; i++)
        printf("%s\n", B[i].c_str());
    return 0;
}