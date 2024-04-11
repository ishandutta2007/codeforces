#include <bits/stdc++.h>
using namespace std;

const int Maxn = 42;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int mx = -2000000000;
        int bi, bj;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int num; scanf("%d", &num);
                if (num > mx) {
                    mx = num;
                    bi = i; bj = j;
                }
            }
        int sid1 = max(bi, n - 1 - bi);
        int sid2 = max(bj, m - 1 - bj);
        printf("%d\n", (sid1 + 1) * (sid2 + 1));
    }
    return 0;
}