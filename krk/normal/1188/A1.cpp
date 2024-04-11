#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() == 2) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}