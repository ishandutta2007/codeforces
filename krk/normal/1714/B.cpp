#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int Solve()
{
    set <int> S;
    for (int i = n - 1; i >= 0; i--) {
        if (S.find(a[i]) != S.end()) return i + 1;
        S.insert(a[i]);
    }
    return 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%d\n", Solve());
    }
    return 0;
}