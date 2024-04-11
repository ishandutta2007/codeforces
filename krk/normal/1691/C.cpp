#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxd = 10;

int T;
int n, k;
int A[Maxd], B[Maxd];
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill(A, A + Maxd, -1);
        fill(B, B + Maxd, -1);
        scanf("%s", str);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int dig = str[i] - '0';
            sum += 11 * dig;
            if (A[dig] == -1) A[dig] = i;
            B[dig] = i;
        }
        int res = 1000000000;
        for (int i = 0; i < Maxd; i++) if (A[i] != -1)
            for (int j = 0; j < Maxd; j++) if (B[j] != -1 && A[i] != B[j]) {
                int nd = n - 1 - B[j] + A[i];
                if (B[j] < A[i]) nd--;
                if (nd <= k)
                    res = min(res, sum - i - 10 * j);
            }
        printf("%d\n", res);
    }
    return 0;
}