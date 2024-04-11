#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int res[Maxn];
set <int> S;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        S.insert(i);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int lst = i > 0? a[i - 1]: 0;
        if (lst < a[i]) {
            res[i] = lst;
            S.erase(lst);
        } else res[i] = -1;
    }
    S.erase(a[n - 1]);
    for (int i = 0; i < n; i++) {
        if (res[i] == -1) {
            res[i] = *S.begin();
            S.erase(S.begin());
        }
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}