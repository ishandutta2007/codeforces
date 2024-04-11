#include <bits/stdc++.h>
using namespace std;

const int Maxl = 200005;
const string rgb = "RGB";

int q;
int n, k;
char str[Maxl];
int acc[Maxl];

int Get(int x)
{
    for (int i = 1; i <= n; i++) {
        acc[i] = acc[i - 1] + (rgb[x] != str[i]);
        x = (x + 1) % 3;
    }
    int res = acc[k];
    for (int i = k + 1; i <= n; i++)
        res = min(res, acc[i] - acc[i - k]);
    return res;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str + 1);
        int res = min(min(Get(0), Get(1)), Get(2));
        printf("%d\n", res);
    }
    return 0;
}