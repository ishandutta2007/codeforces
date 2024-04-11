#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 202;

int T;
int n;
int a[Maxn];
vector <int> my[Maxm];
int sum[Maxn][Maxm];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < Maxm; i++)
            my[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            my[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < Maxm; j++)
                sum[i][j] = sum[i - 1][j];
            sum[i][a[i]]++;
        }
        int res = 0;
        for (int i = 0; i < Maxm; i++) {
            res = max(res, int(my[i].size()));
            for (int j = 0, z = int(my[i].size()) - 1; j < z; j++, z--)
                for (int k = 0; k < Maxm; k++) if (i != k)
                    res = max(res, 2 * (j + 1) + sum[my[i][z] - 1][k] - sum[my[i][j]][k]); 
        }
        printf("%d\n", res);
    }
    return 0;
}