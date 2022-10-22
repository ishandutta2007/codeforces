#include <bits/stdc++.h>
using namespace std;

int a, b;
int res;

int main()
{
    cin >> a >> b;
    while (b > a) {
        res++;
        if (b % 2 == 0) b /= 2;
        else b++;
    }
    res += a - b;
    printf("%d\n", res);
    return 0;
}