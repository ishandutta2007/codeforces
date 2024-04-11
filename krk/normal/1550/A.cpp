#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cur = 1, res = 0;
        while (n > 0) {
            n -= cur;
            res++;
            cur += 2;
        }
        printf("%d\n", res);
    }
    return 0;
}