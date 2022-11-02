#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 105;

int n, x[MAXN], ans = 1e9;
int num[MAXN], imin[MAXN];

bool check(int m) {
    for (int i=0; i<m; i++) {
        num[i] = 0;
        imin[i] = 1e9;
    }

    int k = 0;

    int cur = 0;
    for (int i=0; i<n; i++, cur = (cur+1)%m) {
        if (k > m) return 0;
        if (imin[cur] == num[cur]) {
            k++, i--; continue;
        } else k = 0;
        num[cur] ++;
        imin[cur] = min(imin[cur], x[i] + num[cur]);
    }

    return 1;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> x[i];
    sort(x, x + n);
    reverse(x, x + n);

    for (int i=n; i>0; i--) {
        if (check(i))
            ans = i;
    }

    cout << ans << '\n';
    return 0;
}