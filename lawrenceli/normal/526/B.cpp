#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2050;

int n, a[MAXN], ans;

int dfs(int cur) {
    if (cur >= (1<<n)) return a[cur];
    int x = dfs(2*cur), y = dfs(2*cur+1);
    ans += abs(x-y);
    return max(x, y) + a[cur];
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=2; i<1<<(n+1); i++) cin >> a[i];
    dfs(1);

    cout << ans;
}