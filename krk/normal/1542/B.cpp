#include <bits/stdc++.h>
using namespace std;

int T;
int n, a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        bool res = false;
        if ((n - 1) % b == 0) res = true;
        else if (a > 1) {
            int cur = 1;
            while (cur <= n / a) {
                cur *= a;
                if ((n - cur) % b == 0) res = true;
            }
        }
        printf("%s\n", res? "Yes": "No");
    }
    return 0;
}