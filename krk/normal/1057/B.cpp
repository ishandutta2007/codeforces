#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += a[j];
            int tim = j - i + 1;
            if (sum > 100 * tim) res = max(res, tim);
        }
    }
    printf("%d\n", res);
    return 0;
}