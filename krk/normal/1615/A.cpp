#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            sum += a;
        }
        if (sum % n == 0) printf("0\n");
        else printf("1\n");
    }
    return 0;
}