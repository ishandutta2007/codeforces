#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, x;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int cnt = 0, res = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt++;
            if (a[i] * ll(cnt) >= x) { res++; cnt = 0; }
        }
        printf("%d\n", res);
    }
    return 0;
}