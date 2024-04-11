#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, a, b;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        scanf("%s", str);
        int res = a * n;
        if (b >= 0) res += b * n;
        else {
            int cnt = 0;
            for (int i = 0, j; i < n; i = j) {
                j = i;
                while (j < n && str[i] == str[j]) j++;
                cnt++;
            }
            res += (cnt + 2) / 2 * b;
        }
        printf("%d\n", res);
    }
    return 0;
}