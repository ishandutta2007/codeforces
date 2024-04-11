#include <bits/stdc++.h>
using namespace std;

int q;

int main()
{
    scanf("%d", &q);
    while (q--) {
        int l1, r1, l2, r2; scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (l1 == l2)
            if (r1 >= r2) l1++;
            else l2++;
        printf("%d %d\n", l1, l2);
    }
    return 0;
}