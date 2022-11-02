#include <iostream>

using namespace std;

#define MAXN 500

int n, c[MAXN];
int dp[MAXN][MAXN] = {};

int min_cost(int from, int to)
{
    if (dp[from][to] != 0) return dp[from][to];

    if (from == to) {
        return dp[from][to] = 1;
    } else if (from + 1 == to) {
        return dp[from][to] = 1 + (c[from] != c[to]);
    }
    int ans = 1000;
    if (c[from] == c[to]) {
        ans = min(ans, min_cost(from + 1, to - 1));
    }
    for (int div = from; div < to; div++) {
        ans = min(ans, min_cost(from, div) + min_cost(div + 1, to));
    }
    return dp[from][to] = ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    cout << min_cost(0, n - 1);
    return 0;
}