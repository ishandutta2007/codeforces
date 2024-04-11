#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        if (n % 2 == 0) {
            bool ev = false;
            for (int i = 1; i < n; i += 2)
                if ((str[i] - '0') % 2 == 0)
                    ev = true;
            printf("%c\n", ev? '2': '1');
        } else {
            bool od = false;
            for (int i = 0; i < n; i += 2)
                if ((str[i] - '0') % 2 == 1)
                    od = true;
            printf("%c\n", od? '1': '2');
        }
    }
    return 0;
}