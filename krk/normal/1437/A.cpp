#include <bits/stdc++.h>
using namespace std;

int T;
int l, r;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        printf("%s\n", r < 2 * l? "YES": "NO");
    }
    return 0;
}