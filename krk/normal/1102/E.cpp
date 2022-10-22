#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n;
int a[Maxn];
map <int, int> lst;
int ans = 1;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        lst[a[i]] = i;
    }
    int cur = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i > cur) res++;
        cur = max(cur, lst[a[i]]);
    }
    while (res--)
        ans = 2ll * ans % mod;
    printf("%d\n", ans);
    return 0;
}