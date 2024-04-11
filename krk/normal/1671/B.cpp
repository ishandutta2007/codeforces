#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int x[Maxn];

bool Check(int lst)
{
    for (int i = 1; i < n; i++) {
        lst++;
        if (fabs(x[i] - lst) > 1) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        if (Check(x[0] - 1) || Check(x[0]) || Check(x[0] + 1))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}