#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> res1, res2, res3;

bool Solve()
{
    for (int i = n - 1; i > 0; i--) {
        if (a[i] > a[i + 1]) return false;
        if (a[i] - a[n] <= a[i]) {
            for (int j = 1; j < i; j++) {
                res1.push_back(j);
                res2.push_back(i);
                res3.push_back(n);
            }
            return true;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res1.clear(); res2.clear(); res3.clear();
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (Solve()) {
            printf("%d\n", int(res1.size()));
            for (int i = 0; i < res1.size(); i++)
                printf("%d %d %d\n", res1[i], res2[i], res3[i]);
        } else printf("-1\n");
    }
    return 0;
}