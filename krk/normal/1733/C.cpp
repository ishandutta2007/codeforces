#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int lst = n;
        while (lst > 1 && a[1] % 2 != a[lst] % 2) lst--;
        vector <ii> res;
        for (int i = 1; i < lst; i++)
            if (a[i] % 2 == a[lst] % 2)
                res.push_back(ii(i, lst));
        for (int i = 1; i <= n; i++) if (a[i] % 2 != a[1] % 2)
            res.push_back(ii(1, i));
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}