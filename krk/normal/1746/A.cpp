#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        bool was = false;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a == 1) was = true;
        }
        printf("%s\n", was? "YES": "NO");
    }
    return 0;
}