#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 200100;

int n, m;
int s[MAXN], t[MAXN], ord[MAXN];

map<int, int> mp;
int cnt = 1;

bool cmp(int a, int b) {
    return t[a] < t[b];
}

int dp[MAXN], pre[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    mp[0] = mp[n] = 0;
    for (int i=0; i<m; i++) {
        cin >> s[i] >> t[i];
        mp[s[i]] = 0;
        mp[t[i]] = 0;
        ord[i] = i;
    }
    sort(ord, ord + m, cmp);
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
        mp[it->first] = cnt++;
    for (int i=0; i<m; i++)
        s[i] = mp[s[i]], t[i] = mp[t[i]];

    dp[1] = 1;
    for (int ii=0; ii<m; ii++) {
        int i = ord[ii];
        if (ii)
            for (int j=t[ord[ii-1]]; j<t[ord[ii]]; j++)
                pre[j] = (pre[j-1] + dp[j]) % MOD;
        else
            for (int j=1; j<t[ord[ii]]; j++)
                pre[j] = (pre[j-1] + dp[j]) % MOD;

        dp[t[i]] = (dp[t[i]] + ll(pre[t[i]-1]) - pre[s[i]-1] + MOD) % MOD;
    }

    cout << dp[mp[n]] << '\n';
    return 0;
}