#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 205, L = 6000;
int n, K, f[N][L + 1];
LL a[N];
int main() {
    memset(f, 0xcf, sizeof f);

    scanf("%d%d", &n, &K);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int s2 = 0, s5 = 0;
        while(a[i] % 2 == 0) a[i] /= 2, s2++;
        while(a[i] % 5 == 0) a[i] /= 5, s5++;

        for(int j = K; j; j--)
            for(int k = L; k >= s5; k--)
                f[j][k] = max(f[j][k], f[j - 1][k - s5] + s2);
    }
    
    int ans = 0;
    for(int i = 0; i <= L; i++)
        ans = max(ans, min(i, f[K][i]));
    printf("%d\n", ans);
    return 0;
}