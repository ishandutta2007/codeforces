#include <bits/stdc++.h>
using namespace std;

int b, g;
int n;
bool was[605];

int main()
{
    cin >> b >> g;
    cin >> n;
    for (int i = 0; i <= b && i <= n; i++)
        if (n - i <= g) was[i] = true;
    int res = 0;
    for (int i = 0; i <= n; i++)
        res += was[i];
    printf("%d\n", res);
    return 0;
}