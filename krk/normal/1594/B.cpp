#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int pw = 1;
        int res = 0;
        while (k) {
            if (k & 1) res = (res + pw) % mod;
            k >>= 1;
            pw = ll(pw) * n % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}