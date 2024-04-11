#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100;

int T;
int n;
int a[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = n - 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int A = a[j] - a[i];
                int B = j - i;
                int g = gcd(abs(A), abs(B));
                A /= g; B /= g;
                int cand = 0;
                for (int k = 0; k < n; k++)
                    if ((k - i) % B == 0) {
                        int nd = a[i] + (k - i) / B * A;
                        cand += a[k] != nd;
                    } else cand++;
                res = min(res, cand);
            }
        printf("%d\n", res);
    }
    return 0;
}