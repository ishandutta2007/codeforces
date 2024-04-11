#include <bits/stdc++.h>
using namespace std;

const int Maxd = 4;
const string lets = "UDLR";
const int dy[Maxd] = {1, -1, 0, 0};
const int dx[Maxd] = {0, 0, -1, 1};
const int Maxn = 400005;

int n;
char str[Maxn];
int X, Y;
int res = Maxn;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        str[n + i] = str[i];
    scanf("%d %d", &X, &Y);
    if (((X + Y) % 2 == 0) != (n % 2 == 0) || abs(X) + abs(Y) > n) {
        printf("-1\n");
        return 0;
    }
    int l = 0, r = 0;
    while (true)
        if (abs(X) + abs(Y) <= n - (r - l)) {
            if (l <= n && r >= n)
                res = min(res, n - (r - l));
            if (r >= 2 * n) break;
            X -= dx[lets.find(str[r])];
            Y -= dy[lets.find(str[r])];
            r++;
        } else {
            X += dx[lets.find(str[l])];
            Y += dy[lets.find(str[l])];
            l++;
        }
    cout << res << endl;
    return 0;
}