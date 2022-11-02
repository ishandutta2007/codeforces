#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 1000000007;
char str[1000011];
int n, f[1000011], p[1000011], v[1000011];

int main() {
    scanf("%s", str + 1);
    n = strlen(str + 1);
    memset(f, 0, sizeof(f));
    int cur = n + 1;
    f[n + 1] = 0; f[n + 2] = 0; v[n + 2] = 1;
    int sum = 0, cnt = 0; p[0] = 0;
    f[0] = 0;
    int sx = 0;
    for (int i = n; i; --i) {
        if (str[i] == '1')
            cur = i, cnt = 0;
        else
            ++cnt;
        if (cnt) {
            sum -= f[p[cnt]];
            p[cnt] = cur;
            sum += f[cur];
            if (cur == n + 1)
                ++sx;
        }
        if (cur == i)
            f[i] = f[cur + 1] + sum + sx + 1;
        else 
            f[i] = (cur <= n ? f[cur] : 0); 
        f[i] %= P;
        v[i] = f[i] + sum; v[i] %= P;
        if (sum < 0)
            sum += P;
        if (sum >= P)
            sum -= P;
        //printf("%d %d\n", p[0], p[1]);
        
    }
    if (cur == n + 1)
        printf("%d\n", n);
    else
        printf("%d\n", 1LL * f[cur] * cur % P);
}