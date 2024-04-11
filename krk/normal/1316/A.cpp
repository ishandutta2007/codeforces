#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", min(m, sum));
    }
    return 0;
}