#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxl = 26;

int n, k;
vector <int> V[Maxl];
char str[Maxn];
bool er[Maxn];
char res[Maxn];
int rlen;

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        V[str[i] - 'a'].push_back(i);
    for (int i = 0; i < Maxl; i++) {
        int tk = min(k, int(V[i].size()));
        k -= tk;
        for (int j = 0; j < tk; j++)
            er[V[i][j]] = true;
    }
    for (int i = 0; i < n; i++)
        if (!er[i]) res[rlen++] = str[i];
    res[rlen++] = '\0';
    printf("%s\n", res);
    return 0;
}