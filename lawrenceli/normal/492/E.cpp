#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;

int n, m, dx, dy, p[MAXN], num[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> dx >> dy;

    int x = 0, y = 0;
    do {
        p[x] = y;
        x = (x+dx)%n;
        y = (y+dy)%n;
    } while (x != 0);

    for (int i=0; i<m; i++) {
        cin >> x >> y;
        num[(y+n-p[x])%n]++;
    }

    int ma = -1e8, k = -1;
    for (int i=0; i<n; i++)
        if (num[i] > ma)
            ma = num[i], k = i;

    cout << 0 << ' ' << k;
}