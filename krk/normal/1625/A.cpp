#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, l;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        for (int j = 0; j < l; j++) {
            int ones = 0, zers = 0;
            for (int i = 0; i < n; i++)
                if (a[i] & 1 << j) ones++;
                else zers++;
            if (ones > zers) res |= 1 << j;
        }
        printf("%d\n", res);
    }
    return 0;
}