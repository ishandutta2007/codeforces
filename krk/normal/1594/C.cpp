#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n;
char c;
char str[Maxn];

bool Check(int x)
{
    for (int i = x; i <= n; i += x)
        if (str[i] != c) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %c", &n, &c);
        scanf("%s", str + 1);
        if (Check(1)) printf("0\n");
        else {
            bool ok = false;
            for (int i = 2; i <= n; i++)
                if (Check(i)) {
                    ok = true;
                    printf("1\n%d\n", i);
                    break;
                }
            if (!ok) printf("2\n%d %d\n", n - 1, n);
        }
    }
    return 0;
}