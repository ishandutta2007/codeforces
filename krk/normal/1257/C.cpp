#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> V[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            V[i].clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            V[a].push_back(i);
        }
        int res = Maxn;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < V[i].size(); j++)
                res = min(res, V[i][j] - V[i][j - 1] + 1);
        printf("%d\n", res >= Maxn? -1: res);
    }
    return 0;
}