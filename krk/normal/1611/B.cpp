#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int res = (a + b) / 4;
        res = min(res, min(a, b));
        printf("%d\n", res);
    }
    return 0;
}