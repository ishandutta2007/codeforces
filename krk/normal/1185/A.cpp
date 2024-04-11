#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int res;

int main()
{
    cin >> a >> b >> c >> d;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    res = max(0, d - (b - a)) + max(0, d - (c - b));
    printf("%d\n", res);
    return 0;
}