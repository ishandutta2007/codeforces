#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n, m;
int n1, n2, n3;
vector <int> neigh[Maxn];
int col[Maxn];
int comp;
vector <int> A[Maxn], B[Maxn];
vector <int> oth;
bool dp[Maxn][Maxn];
char res[Maxn];

bool Traverse(int v, int c, vector <int> &A, vector <int> &B)
{
    if (col[v]) return col[v] == c;
    col[v] = c; A.push_back(v);
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Traverse(neigh[v][i], -c, B, A))
            return false;
    return true; 
}

void Select(const vector <int> &A, const vector <int> &B)
{
    for (int i = 0; i < A.size(); i++)
        res[A[i]] = '2';
    for (int i = 0; i < B.size(); i++)
        oth.push_back(B[i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &n1, &n2, &n3);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!col[i])
        if (!Traverse(i, -1, A[comp], B[comp])) {
            printf("NO\n");
            return 0;
        } else comp++;
    dp[0][0] = true;
    for (int i = 0; i < comp; i++)
        for (int j = 0; j <= n; j++) if (dp[i][j]) {
            dp[i + 1][j + A[i].size()] = true;
            dp[i + 1][j + B[i].size()] = true;
        }
    if (!dp[comp][n2]) {
        printf("NO\n");
        return 0;
    }
    int curi = comp, curj = n2;
    while (curi > 0) {
        if (A[curi - 1].size() <= curj && dp[curi - 1][curj - int(A[curi - 1].size())]) {
            Select(A[curi - 1], B[curi - 1]);
            curj -= int(A[curi - 1].size());
        } else {
            Select(B[curi - 1], A[curi - 1]);
            curj -= int(B[curi - 1].size());
        }
        curi--;
    }
    while (n1--) {
        res[oth.back()] = '1';
        oth.pop_back();
    }
    while (!oth.empty()) {
        res[oth.back()] = '3';
        oth.pop_back();
    }
    res[n + 1] = '\0';
    printf("YES\n");
    printf("%s\n", res + 1);
    return 0;
}