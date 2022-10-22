#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            printf("%s", string(i, '(').c_str());
            printf("%s", string(i, ')').c_str());
            if (i < n) {
                printf("%s", string(n - i, '(').c_str());
                printf("%s", string(n - i, ')').c_str());
            }
            printf("\n");
        }
    }
    return 0;
}