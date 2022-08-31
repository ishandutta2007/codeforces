#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> v[max_n];
int n;
int dp[max_n];

void dfs(int cur) {
    if (v[cur].size() == 0) {
        dp[cur] = 1;
        return;
    }
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        dfs(to);
        dp[cur] += dp[to];
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int pr;
        cin >> pr;
        --pr;
        v[pr].PB(i);
    }
    dfs(0);
    sort(dp, dp + n);
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << ' ';
    }

    return 0;
}