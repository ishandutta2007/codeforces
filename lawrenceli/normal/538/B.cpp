#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000100;

vector<int> nums;
int n, dp[MAXN], par[MAXN];

bool good(int x) {
    while (x) {
        if (!(x%10 == 0 || x%10 == 1)) return 0;
        x /= 10;
    } return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++)
        if (good(i)) nums.push_back(i);


    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        dp[i] = 1e9;
        for (int j : nums)
            if (i-j >= 0 && dp[i-j]+1 < dp[i])
                dp[i] = dp[i-j]+1, par[i] = j;
    }

    vector<int> ans;
    int cur = n;
    while (cur) {
        ans.push_back(par[cur]);
        cur -= par[cur];
    }

    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}