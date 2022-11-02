#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int test, n, c[2000011], m; 
char str[2000011];
long long t[2000011];

int main() {
    scanf("%s", str + 1);
    n = strlen(str + 1);
    int k = 200;
    m = 0;
    long long ans = 0;
    for (int j = 1; j <= k; j++) {
        //t.clear();
        m = 0; long long cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i && str[i] == '1')
                c[++m] = i, ++cnt;
                t[i] = cnt * j - i;
    //`            printf("%d %d\n", j, cnt * j - i);
        }
        sort(t, t + n + 1);
        int cnct = 0;
        for (int i = 0; i <= n; i++) {
            if (!i || t[i] != t[i - 1])
                cnct = 0;
            ans += cnct;
            ++cnct;
        }
    }
    
    for (int i = 1; i <= n / k; i++)
        for (int j = 1; j <= m - i + 1; j++) {
            int r1 = c[j + i - 1], r2 = n;
            if (j + i - 1 != m)
                r2 = c[j + i] - 1;
            int l2 = c[j] - 1, l1 = 0;
            if (j != 1)
                l1 = c[j - 1];
            
            for (int l = r1; l <= r2; l++) {
            int D = max((l - l2 - 1) / i + 1, k + 1);
            int U = (l - l1) / i;
            if (U >= D)
                ans += U - D + 1;
                //cout << ans << endl;
            }
        }
    printf("%lld\n", ans);
}