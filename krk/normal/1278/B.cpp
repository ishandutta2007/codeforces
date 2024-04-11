#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int a, b;

int main()
{
    scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        if (a == b) { printf("0\n"); continue; }
        int nd = abs(a - b);
        ll sum = 0;
        int i = 0;
        while (sum < nd || sum % 2 != nd % 2)
            sum += ++i;
        printf("%d\n", i);
    }
    return 0;
}