#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 1000100;

int n, ans[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    cin >> n;
    memset(ans, -1, sizeof(ans));

    int k = 30;
    for (int i=n; i>0; i--) {
        if (ans[i] != -1) continue;
        while (1<<(k-1) > i) k--;
        int x = ((1<<k) - 1) ^ i;
        ans[x] = i; ans[i] = x;
    }

    if (ans[0] == -1) ans[0] = 0;

    cout << (long long)n * (n+1) << endl;
    for (int i=0; i<=n; i++) cout << ans[i] << ' ';

    return 0;
}