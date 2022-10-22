#include <bits/stdc++.h>
using namespace std;

int T;
int n, s;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &s);
        int res = s / ((n + 2) / 2);
        printf("%d\n", res);
    }
    return 0;
}