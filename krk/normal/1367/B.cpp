#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int od = 0, ev = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (i % 2 == 0 && a % 2 != 0) od++;
            else if (i % 2 != 0 && a % 2 == 0) ev++;
        }
        if (ev != od) printf("-1\n");
        else printf("%d\n", ev);
    }
    return 0;
}