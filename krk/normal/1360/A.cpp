#include <bits/stdc++.h>
using namespace std;

int t;
int a, b;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        a = max(2 * a, b);
        printf("%d\n", a * a);
    }
    return 0;
}