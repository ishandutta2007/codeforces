#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxk = 102;
const int mod = 998244353;

int n, k, len;
ii seq[Maxk][Maxn];
int sum[Maxk];
int beg[Maxk], en[Maxk];
int res;

int main()
{
    scanf("%d %d %d", &n, &k, &len);
    if (len == 1) { printf("0\n"); return 0; }
    int a; scanf("%d", &a);
    for (int i = 1; i <= k; i++)
        if (a == i || a == -1) { seq[i][en[i]++] = ii(0, 1); sum[i] = 1; }
    for (int i = 1; i < n; i++) {
        scanf("%d", &a);
        int tsum = 0;
        for (int j = 1; j <= k; j++) {
            while (beg[j] < en[j] && i - seq[j][beg[j]].first >= len) {
                sum[j] = (sum[j] - seq[j][beg[j]].second + mod) % mod;
                beg[j]++;
            }
            tsum = (tsum + sum[j]) % mod;
        }
        if (a == -1)
            for (int j = 1; j <= k; j++) {
                int give = (tsum - sum[j] + mod) % mod;
                seq[j][en[j]++] = ii(i, give); sum[j] = (sum[j] + give) % mod;
            }
        else {
            int give = (tsum - sum[a] + mod) % mod;
            seq[a][en[a]++] = ii(i, give); sum[a] = (sum[a] + give) % mod;
            for (int j = 1; j <= k; j++) if (j != a) {
                beg[j] = en[j]; sum[j] = 0;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        while (beg[i] < en[i] && n - seq[i][beg[i]].first >= len) {
            sum[i] = (sum[i] - seq[i][beg[i]].second + mod) % mod;
            beg[i]++;
        }
        res = (res + sum[i]) % mod;
    }
    printf("%d\n", res);
    return 0;
}