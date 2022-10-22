#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    cin >> T;
    while (T--) {
        int x, y; cin >> x >> y;
        if ((x + y) % 2) printf("-1 -1\n");
        else printf("%d %d\n", x / 2, (y + 1) / 2);
    }
    return 0;
}