#include <bits/stdc++.h>
using namespace std;

int x, y, z, t1, t2, t3;

int main()
{
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int res1 = 3 * t3 + t2 * (abs(x - z) + abs(x - y));
    int res2 = abs(x - y) * t1;
    if (res1 <= res2) printf("YES\n");
    else printf("NO\n");
    return 0;
}