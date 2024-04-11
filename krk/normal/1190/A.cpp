#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll n;
int m;
ll k;
ll a[Maxn];
int res;

int main()
{
    scanf("%I64d %d %I64d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &a[i]);
        a[i]--;
    }
    for (int i = 0, j; i < m; i = j) {
        res++;
        j = i;
        while (j < m && (a[i] - i) / k == (a[j] - i) / k)
            j++;
    }
    printf("%d\n", res);
    return 0;
}