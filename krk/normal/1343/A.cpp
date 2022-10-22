#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cur = 1;
        while (true) {
            cur = 2 * cur + 1;
            if (n % cur == 0) {
                printf("%d\n", n / cur);
                break;
            }
        }
    }
    return 0;
}