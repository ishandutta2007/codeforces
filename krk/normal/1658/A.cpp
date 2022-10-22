#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int res = 0;
        for (int i = 0; i < n; )
            if (str[i] == '1') i++;
            else if (i + 1 < n && str[i + 1] == '0') { res += 2; i++; }
                 else if (i + 2 < n && str[i + 2] == '0') { res++; i += 2; }
                 else i++;
        printf("%d\n", res);
    }
    return 0;
}