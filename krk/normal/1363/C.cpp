#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, x;
vector <int> neigh[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        if (neigh[x].size() <= 1 || n % 2 == 0) { printf("Ayush\n"); continue; }
        else printf("Ashish\n");
    }
    return 0;
}