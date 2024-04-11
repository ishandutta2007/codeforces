#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < 2 * n; i++) {
            int a; scanf("%d", &a);
            if (a % 2) res++;
            else res--;
        }
        printf("%s\n", res == 0? "Yes": "No");
    }
    return 0;
}