#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int t;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll sum1 = 0, mx = -2000000000000000007ll;
        map <ll, int> M;
        M[0]++;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum1 += a[i];
            if (i == n - 1)
                if (--M[0] == 0) M.erase(0);
            if (!M.empty())
                mx = max(mx, sum1 - M.begin()->first);
            M[sum1]++;
        }
        printf("%s\n", sum1 > mx? "YES": "NO");
    }
    return 0;
}