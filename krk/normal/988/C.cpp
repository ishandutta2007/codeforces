#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int k;
int n;
int a[Maxn];
map <int, ii> M;

int main()
{
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &n);
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
            sum += a[j];
        }
        for (int j = 1; j <= n; j++) {
            auto it = M.find(sum - a[j]);
            if (it != M.end()) {
                printf("YES\n");
                printf("%d %d\n", it->second.first, it->second.second);
                printf("%d %d\n", i, j);
                return 0;
            }
        }
        for (int j = 1; j <= n; j++)
            M[sum - a[j]] = ii(i, j);
    }
    printf("NO\n");
    return 0;
}