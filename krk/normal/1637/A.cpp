#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int lst = 0;
        bool fall = false;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a < lst) fall = true;
            lst = a;
        }
        printf("%s\n", !fall? "NO": "YES");
    }
    return 0;
}