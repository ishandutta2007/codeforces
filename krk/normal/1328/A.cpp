#include <bits/stdc++.h>
using namespace std;

int t;
int a, b;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        int tk = a - a / b * b;
        if (tk != 0) tk = b - tk;
        printf("%d\n", tk);
    }
    return 0;
}