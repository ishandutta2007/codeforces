#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int maxn = 8005;
const int inf = 1e9;

int n;
char s[maxn];

int dp[maxn];
int z[maxn]; //z algorithm
int p[maxn]; //period of string [t, r)
pii stk[maxn]; int stksze;

void doz(int t) {
    int l = -1, r = -1;
    for (int i = t + 1; i <= n; i++) {
        if (i >= r) {
            l = r = i;
            while (r < n && s[r] == s[t + r - l]) r++;
            z[i] = r - l;
        } else {
            int k = z[t + i - l];
            if (i + k >= r) {
                l = i;
                while (r < n && s[r] == s[t + r - l]) r++;
                z[i] = r - l;
            } else z[i] = k;
        }
    }

    // calculate periods, period of string [t, i) is smallest j > t
    // s.t. z[j] + j >= i

    stksze = 0;
    int pnt = 0;
    for (int i = t + 1; i <= n; i++) {
        if (stksze == 0 || stk[stksze - 1].second < z[i] + i)
            stk[stksze++] = pii(i, z[i] + i);
        while (pnt < stksze && stk[pnt].second < i) pnt++;
        assert(pnt < stksze);
        p[i] = stk[pnt].first - t;
        if ((i - t) % p[i] != 0) p[i] = i - t;
    }
}

int numdig(int x) {
    int ret = 0;
    while (x) ret++, x /= 10;
    return ret;
}

void setmin(int& a, int b) { if (a > b) a = b; }

int main() {
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < maxn; i++)
        dp[i] = inf;

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        doz(i);
        for (int j = i + 1; j <= n; j++) {
            int val = p[j] + numdig((j - i) / p[j]);
            setmin(dp[j], dp[i] + val);
        }
        //cout << dp[i] << ' ';
    }

    printf("%d\n", dp[n]);
}