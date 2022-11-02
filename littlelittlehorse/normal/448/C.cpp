#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct point{
    int value, position;
    bool operator < (const point &A) const{
        return value < A.value;
    }
} a[5001];
long long f[5001][5001];
int n, h[5001], c[5001];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].value), a[i].position = i;
    sort(a + 1, a + n + 1);
    int cnt = 0; c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || a[i].value != a[i - 1].value) c[++cnt] = a[i].value;
        h[a[i].position] = cnt;
    }
    memset(f, 127, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        long long Min = 1LL << 60LL;
        for (int j = cnt; j >= 0; --j)
        {
            Min = min(Min, f[i - 1][j]);
            if (j == h[i]) f[i][j] = Min;
            else if (j < h[i]) f[i][j] = Min + 1;
        }
        for (int j = 1; j < h[i]; j++)
            f[i][j] = min(f[i][j], f[i][j - 1] + c[j] - c[j - 1]);
        f[i][h[i]] = min(f[i][h[i]], f[i][h[i] - 1] + c[h[i]] - c[h[i] - 1] - 1);
    }
    long long ans = 1LL << 60LL;
    //for (int i = 1; i <= n; i++)
    //  for (int j = 0; j <= h[i]; j++) printf("%d %d %d\n", i, j, f[i][j]);
    for (int i = 0; i <= h[n]; i++) ans = min(ans, f[n][i]);
    cout << ans << endl;
}