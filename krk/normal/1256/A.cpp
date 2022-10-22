#include <bits/stdc++.h>
using namespace std;

int q;
int a, b, n, S;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d %d", &a, &b, &n, &S);
        int tk = min(S / n, a);
        if (S - tk * n <= b) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}