#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

int n;
vector <int> gr[Maxn];

int main()
{
    scanf("%d", &n);
    bool inv = false;
    for (int i = 1; i <= n * n; i += n, inv = !inv)
        if (inv)
            for (int j = 1; j <= n; j++)
                gr[j].push_back(i + n - j);
        else for (int j = 1; j <= n; j++)
                gr[j].push_back(i + j - 1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < gr[i].size(); j++)
            printf("%d%c", gr[i][j], j + 1 < gr[i].size()? ' ': '\n');
    return 0;
}