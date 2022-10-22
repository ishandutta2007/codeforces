#include <bits/stdc++.h>
using namespace std;

const int Maxd = 6;
const int my[Maxd] = {4, 8, 15, 16, 23, 42};

int n;
int a[Maxd];
int cnt[Maxd + 1];

int main()
{
    scanf("%d", &n);
    cnt[0] = n;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        int p = 0;
        while (my[p] != a) p++;
        if (cnt[p] > 0) {
            cnt[p]--;
            cnt[p + 1]++;
        }
    }
    printf("%d\n", n - 6 * cnt[Maxd]);
    return 0;
}