#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 20;

int T;
int n;
ll a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int twos = 0;
        for (int i = 0; i < n; i++) {
            scanf("%I64d", &a[i]);
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                twos++;
            }
        }
        sort(a, a + n);
        while (twos--)
            a[n - 1] *= 2ll;
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        printf("%I64d\n", sum);
    }
    return 0;
}