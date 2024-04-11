#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        map <int, int> M;
        for (int i = 0; i < 2 * k; i++)
            M[a[--n]]++;
        int mx = 0;
        for (auto it: M)
            mx = max(mx, it.second);
        int res = 0;
        for (int i = 0; i < n; i++)
            res += a[i];
        if (mx > k) {
            int lft = 2 * k - mx;
            int tk = min(mx, lft);
            res += (mx - tk) / 2;
        }
        printf("%d\n", res);
    }   
    return 0;
}