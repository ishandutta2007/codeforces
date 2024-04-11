#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 30005;
const int Maxstr = 200005;
const int Inf = 2000000007;

char str[Maxstr];
int t;
int n, m, k;
int freq[Maxl];
bool dp[Maxn];
int res;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%s", str);
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < k; i++)
            freq[str[i] - 'A']++;
        res = Inf;
        int mx = max(n, m);
        for (int i = 0; i < Maxl; i++) {
            int tot = 0;
            for (int j = 0; j < Maxl; j++) if (j != i)
                tot += freq[j];
            int mn = tot;
            fill(dp, dp + mx + 1, false); dp[0] = true;
            for (int j = 0; j < Maxl; j++) if (j != i)
                for (int l = mx; l >= 0; l--) if (dp[l])
                    if (l + freq[j] > mx) mn = min(mn, l + freq[j]);
                    else dp[l + freq[j]] = true;
            for (int l = 0; l <= mx; l++) if (dp[l]) {
                int a = l, b = tot - l;
                int mya = max(0, n - a), myb = max(0, m - b);
                if (mya + myb <= freq[i]) res = min(res, mya * myb);
                mya = max(0, n - b), myb = max(0, m - a);
                if (mya + myb <= freq[i]) res = min(res, mya * myb);
            }
            int a = mn, b = tot - mn;
            int mya = max(0, n - a), myb = max(0, m - b);
            if (mya + myb <= freq[i]) res = min(res, mya * myb);
            mya = max(0, n - b), myb = max(0, m - a);
            if (mya + myb <= freq[i]) res = min(res, mya * myb);
        }
        printf("%d\n", res);
    }
    return 0;
}