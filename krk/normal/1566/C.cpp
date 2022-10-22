#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char B[2][Maxn];

int Add(bool has0, bool has1)
{
    if (!has0) return 0;
    if (!has1) return 1;
    return 2;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; i++)
            scanf("%s", B[i]);
        bool has0 = false, has1 = false;
        int res = 0;
        for (int i = 0; i < n; i++) {
            bool cur0 = (B[0][i] == '0' || B[1][i] == '0');
            bool cur1 = (B[0][i] == '1' || B[1][i] == '1');
            if (cur0 && cur1) {
                res += Add(has0, has1);
                res += 2;
                has0 = has1 = false;
            } else if (cur0 && has0) {
                    res += Add(has0, has1);
                    has0 = cur0;
                    has1 = cur1;
                } else {
                    has0 |= cur0;
                    has1 |= cur1;
                    if (has0 && has1) {
                        res += 2;
                        has0 = has1 = false;
                    }   
                }
        }
        res += Add(has0, has1);
        printf("%d\n", res);
    }
    return 0;
}