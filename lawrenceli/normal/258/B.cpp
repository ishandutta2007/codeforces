#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int m[11], len;
int dp[11][10][10]; //digit position, digit value, number lucky
int num[10]; //numbers <= m with specified # lucky numbers

bool lucky(int x) {
    return x == 4 || x == 7;
}

void init() {
    for (int i=0; i<10; i++)
        dp[0][i][lucky(i)] = 1;

    for (int i=1; i<=10; i++)
        for (int j=0; j<10; j++)
            for (int k=0; k<10; k++) {
                if (lucky(j) && !k) continue; //impossible
                for (int l=0; l<10; l++)
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][l][k-lucky(j)]) % MOD;
            }

    int cur = 0;
    for (int i=len-1; i>=0; i--) {
        for (int j=0; j<m[i]; j++)
            for (int k=0; k+cur<10; k++)
                num[k+cur] = (num[k+cur] + dp[i][j][k]) % MOD;
        cur += lucky(m[i]);
    }

    num[0] --;
    num[cur] ++;
}

int freq[10];
int ans;

int P(int n, int k) {
    int ret = 1;
    for (int i=n; i>n-k; i--) ret = (ll(ret) * i) % MOD;
    return ret;
}

void dfs(int cur) {
    if (cur == 6) {
        for (int i=0; i<10; i++)
            if (freq[i] > num[i])
                return;
        int sum = 0;
        for (int i=0; i<10; i++) sum = sum + freq[i] * i;
        int x = 0;
        for (int i=sum+1; i<10; i++) x = (x + num[i]) % MOD;
        int y = 1;
        for (int i=0; i<10; i++) y = (ll(y) * P(num[i], freq[i])) % MOD;
        ans = (ans + ll(x) * y % MOD) % MOD;
    } else {
        for (int i=0; i<10; i++) {
            freq[i] ++;
            dfs(cur+1);
            freq[i] --;
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string s; cin >> s;
    len = s.length();
    for (int i=0; i<len; i++)
        m[len-1-i] = s[i] - '0';

    init();

    dfs(0);

    cout << ans << '\n';
    return 0;
}