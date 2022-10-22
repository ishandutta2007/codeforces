#include <bits/stdc++.h>
using namespace std;

int t;
int n, k1, k2;
int mx1, mx2;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &k1, &k2);
        mx1 = 0;
        for (int i = 0; i < k1; i++) {
            int a; scanf("%d", &a);
            mx1 = max(mx1, a);
        }
        mx2 = 0;
        for (int i = 0; i < k2; i++) {
            int a; scanf("%d", &a);
            mx2 = max(mx2, a);
        }
        printf("%s\n", mx1 > mx2? "YES": "NO");
    }
    return 0;
}