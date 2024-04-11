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
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ll sum = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            int mx = a[i];
            while (j < n && (a[i] < 0) == (a[j] < 0)) {
                mx = max(mx, a[j]);
                j++;
            }
            sum += mx;
        }
        printf("%I64d\n", sum);
    }
    return 0;
}