#include <bits/stdc++.h>
using namespace std;

int n, d, e;
int res = 1000000000;

int main()
{
    cin >> n >> d >> e;
    e *= 5;
    for (int i = 0; i * e <= n; i++)
        res = min(res, (n - i * e) % d);
    printf("%d\n", res);
    return 0;
}