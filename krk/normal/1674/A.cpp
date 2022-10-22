#include <bits/stdc++.h>
using namespace std;

int T;
int x, y;

int main()
{
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (y % x == 0) printf("1 %d\n", y / x);
        else printf("0 0\n");
    }
    return 0;
}