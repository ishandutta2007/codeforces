#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int lefx, rigx;
int lefy, rigy;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        lefx = rigx = lefy = rigy = 0;
        for (int i = 0; i < n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            lefx = min(lefx, x);
            rigx = max(rigx, x);
            lefy = min(lefy, y);
            rigy = max(rigy, y);
        }
        printf("%d\n", 2 * (rigx - lefx + rigy - lefy));
    }
    return 0;
}