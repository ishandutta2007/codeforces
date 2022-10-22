#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
char str[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        fill(res, res + n, 0);
        if (k % 2)
            for (int i = 0; i < n; i++)
                str[i] = str[i] == '0'? '1': '0';
        for (int i = 0; i < n && k > 0; i++)
            if (str[i] == '0') { str[i] = '1'; res[i]++; k--; }
        if (k % 2) {
            str[n - 1] = '0';
            res[n - 1]++;
            k--;
        }
        res[0] += k;
        printf("%s\n", str);
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}