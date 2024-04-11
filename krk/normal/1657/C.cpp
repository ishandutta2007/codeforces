#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int pnt = 0, res = 0;
        while (pnt + 1 < n)
            if (str[pnt] == '(') {
                pnt += 2;
                res++;
            } else {
                int j = pnt + 1;
                while (j < n && str[j] == '(') j++;
                if (j < n) {
                    res++;
                    pnt = j + 1;
                } else break;
            }
        printf("%d %d\n", res, n - pnt);
    }
    return 0;
}