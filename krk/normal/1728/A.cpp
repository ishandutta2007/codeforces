#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int mx, wth;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        mx = 0;
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (a > mx) {
                mx = a; wth = i;
            }
        }
        printf("%d\n", wth);
    }
    return 0;
}