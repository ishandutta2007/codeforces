#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> V[Maxn];
set <int> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            V[i].clear();
        S.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            int my = max(1, i - (a[i] - 1));
            V[my].push_back(i);
        }
        S.insert(n + 1);
        long long res = 0;
        for (int i = n; i > 0; i--) {
            auto it = S.lower_bound(i);
            res += *it - i;
            for (int j = 0; j < V[i].size(); j++)
                S.insert(V[i][j]);
        }
        printf("%I64d\n", res);
    }
    return 0;
}