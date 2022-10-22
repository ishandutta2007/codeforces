#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int res = 0;
    int i = 1;
    while (i <= n) {
        res++;
        int cur = a[i];
        while (i < cur) {
            i++;
            cur = max(cur, a[i]);
        }
        i++;
    }
    printf("%d\n", res);
    return 0;
}