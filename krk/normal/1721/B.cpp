#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, sx, sy, d;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> m >> sx >> sy >> d;
        if ((sx - d <= 1 || sy + d >= m) && (sx + d >= n || sy - d <= 1))
            printf("-1\n");
        else printf("%d\n", n - 1 + m - 1);
    }
    return 0;
}