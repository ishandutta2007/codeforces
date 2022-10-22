#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d ", a < c? 1: -1);
        printf("%d\n", c < ll(a) * b? b: -1);
    }
    return 0;
}