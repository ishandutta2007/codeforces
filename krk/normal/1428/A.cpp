#include <bits/stdc++.h>
using namespace std;

int T;
int x1, y1, x2, y2;

int main()
{
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int res = abs(x1 - x2) + abs(y1 - y2);
        if (x1 != x2 && y1 != y2) res += 2;
        printf("%d\n", res);
    }
    return 0;
}