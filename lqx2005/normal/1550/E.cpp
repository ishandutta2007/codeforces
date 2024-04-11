#include <bits/stdc++.h>

using namespace std;
typedef double db;
typedef long long i64;
const int N = 2e5 + 10, K = 17, oo = 0x3f3f3f3f;
int n, k, cnt[K];
char s[N];
int nxt[N][K];
int dp[1 << K];
int check(int len) {
    memset(cnt, 0, sizeof(cnt));
    memset(nxt, 0x3f, sizeof(nxt));
    for(int i = 1; i <= n; i++) {
        if(s[i] != '?') cnt[s[i] - 'a']++;
        if(i > len && s[i - len] != '?') cnt[s[i - len] - 'a']--;
        if(i - len >= 0) {
            int flag = 0;
            for(int j = 0; j < k; j++) {
                if(cnt[j] > 0) {
                    flag++;
                }
            }
            for(int j = 0; j < k; j++) {
                if(!flag) nxt[i - len + 1][j] = i;
                if(flag == 1 && cnt[j]) nxt[i - len + 1][j] = i;
            }
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < k; j++) {
            nxt[i][j] = min(nxt[i + 1][j], nxt[i][j]);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i < (1 << k); i++) {
        for(int j = 0; j < k; j++) {
            if(i >> j & 1) {
                if(dp[i ^ (1 << j)] >= oo) continue;
                dp[i] = min(dp[i], nxt[dp[i ^ (1 << j)] + 1][j]);
            }
        }
    }
    return dp[(1 << k) - 1] < oo;
}

int main() {
    cin >> n >> k;
    cin >> (s + 1);
    int L = 0, R = n, best = 0;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid)) best = mid, L = mid + 1;
        else R = mid - 1;
    }
    cout << best << endl;
    return 0;
}