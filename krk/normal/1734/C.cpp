#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n;
char has[Maxn];
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(has + 1, has + n + 1, '1');
        scanf("%s", str + 1);
        long long res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j += i)
                if (str[j] == '1') break;
                else if (has[j] == '1') {
                    has[j] = '0';
                    res += i;
                }
        printf("%I64d\n", res);
    }
    return 0;
}