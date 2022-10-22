#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        ll my = sum % n;
        if (my == 0) printf("0\n");
        else {
            ll a = my, b = n - my;
            printf("%I64d\n", a * b);
        }
    }
    return 0;
}