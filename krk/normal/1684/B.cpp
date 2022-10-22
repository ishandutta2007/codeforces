#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        int my = c / b * b + b;
        my += a;
        printf("%d %d %d\n", my, b, c);
    }
    return 0;
}