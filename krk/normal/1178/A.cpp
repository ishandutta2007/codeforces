#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum2 += a[i];
    }
    vector <int> res;
    res.push_back(1); sum1 += a[1]; sum2 -= a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] * 2 <= a[1]) {
            res.push_back(i);
            sum1 += a[i];
            sum2 -= a[i];
        }
    if (sum1 > sum2) {
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    } else printf("0\n");
    return 0;
}