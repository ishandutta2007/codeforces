#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    if (sum % 2 || a[n - 1] > sum - a[n - 1])
        printf("NO\n");
    else printf("YES\n");
    return 0;
}