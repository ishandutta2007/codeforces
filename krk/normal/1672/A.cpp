#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            sum += a - 1;
        }
        if (sum % 2) printf("errorgorn\n");
        else printf("maomao90\n");
    }
    return 0;
}