#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const L = 8001;

char s[L];
int n;

int best[L][L];

bool prime[L];
set< int > dv[L];
int dp[L][L];
int f[L];

int getLen(int x) {
    if(x == 0) return 0;
    int res = 0;
    while(x) {
        res++;
        x /= 10;
    }
    return res;
}

void precalc() {
    for(int i = 0;i < L;i++) {
        prime[i] = 1;
        f[i] = getLen(i);
    }
    prime[0] = prime[1] = 0;
    for(int i = 2;i * i < L;i++) {
        for(int j = i * i;j < L;j += i) {
            prime[j] = 0;
        }
    }
    for(int i = 2;i < L;i++) {
        if(!prime[i]) continue;
        for(int j = i;j < L;j += i) {
            dv[j].insert(i);
        }
    }
    for(int i = 1;i < L;i++) {
        for(int j = 1;j <= i;j++) {
            if(i % j) continue;
            dp[i][j] = getLen(j) + i / j;
            for(int p : dv[j]) {
                dp[i][j] = min(dp[i][j], dp[i][j / p]);
            }
        }
    }
}

int ans[L];
int ze[L];

void makeZe(int sf) {
    ze[0] = 0;
    for(int l = 1, r = 0, i = 1;i < n - sf;i++) {
        ze[i] = 0;
        if(i <= r) {
            ze[i] = min(ze[i - l], r - i + 1);
        }
        while(i + ze[i] < n - sf && s[ze[i] + sf] == s[i + ze[i] + sf]) {
            ze[i]++;
        }
        if(i + ze[i] - 1 > r) {
            l = i;
            r = i + ze[i] - 1;
        }
    }
}

bitset< L > Equal[L];

void build() {
    for(int i = 0;i < n;i++) {
        makeZe(i);
        for(int j = i;j + (j - i + 1) < n;j++) {
            Equal[i][j] = ze[j + 1 - i] >= j - i + 1;
        }
    }
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%s", s);

    n = strlen(s);

    build();

    for(int l = 0;l < n;l++) {
        for(int r = l;r < n;r++) {
            best[l][r] = -1;
        }
    }

    for(int ln = 1;ln <= n;ln++) {
        for(int i = 0;i + ln - 1 < n;i++) {
            if(best[i][i + ln - 1] != -1) continue;
            int j = i;
            while(1) {
                if(best[i][j + ln - 1] == -1 ||
                   best[i][j + ln - 1] > ln) {
                    best[i][j + ln - 1] = ln;
                }
                if(j + 2 * ln - 1 < n && Equal[j][j + ln - 1]) {
                    j += ln;
                }else {
                    break;
                }
            }
        }
    }

    for(int i = 0;i < L;i++) {
        ans[i] = inf;
    }

    for(int i = 0;i < n;i++) {
        for(int q, j = i;j >= 0;j--) {
            q = dp[i - j + 1][(i - j + 1) / best[j][i]];
            ans[i] = min(ans[i], (j > 0 ? ans[j - 1] : 0) + q); 
        }
    }

    printf("%d\n", ans[n - 1]);

    return 0;
}