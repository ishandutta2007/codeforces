#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll mn = -1, mx = -1;

void Check(int a, int bc)
{
     for (int b = 1; b * b <= bc; b++)
         if (bc % b == 0) {
                int c = bc / b;
                ll cur = ll(a + 1) * ll(b + 2) * ll(c + 2) - ll(a) * ll(b) * ll(c);
                if (mn == -1 || cur < mn) mn = cur;
                if (cur > mx) mx = cur;
         }
}

int main()
{
    scanf("%d", &n);
    for (int d = 1; d * d <= n; d++)
        if (n % d == 0) {
              Check(d, n / d);
              Check(n / d, d);
        }
    printf("%I64d %I64d\n", mn, mx);
    return 0;
}