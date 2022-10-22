#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 2) printf("-1\n");
        else printf("%d 0 0\n", n / 2);
    }
    return 0;
}