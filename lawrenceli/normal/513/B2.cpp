#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 55;

int n, ans[MAXN];
ll m;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    int l=0, r=n-1;
    for (int i=1; i<=n; i++) {
        if (m <= (1LL<<(n-i-1))) ans[l++] = i;
        else ans[r--] = i, m -= (1LL<<(n-i-1));
    }
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
    return 0;
}