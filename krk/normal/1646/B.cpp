#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

bool Solve()
{
    sort(a, a + n);
    ll sumb = a[0], sumr = 0;
    int l = 1, r = n - 1;
    while (l < r && sumb >= sumr) {
        sumb += a[l++];
        sumr += a[r--];
    }
    return sumb < sumr;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}