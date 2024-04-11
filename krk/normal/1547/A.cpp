#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int T;
ii a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a.first, &a.second);
        scanf("%d %d", &b.first, &b.second);
        scanf("%d %d", &c.first, &c.second);
        if (a > b) swap(a, b);
        int res = abs(a.first - b.first) + abs(a.second - b.second);
        if (a <= c && c <= b)
            if (a.first == b.first && b.first == c.first || a.second == b.second && b.second == c.second)
                res += 2;
        printf("%d\n", res);
    }
    return 0;
}