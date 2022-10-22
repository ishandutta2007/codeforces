#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cur = n;
        for (int i = n - 1; i > 0; i--)
            cur = (cur + i + 1) / 2;
        printf("%d\n", cur);
        cur = n;
        for (int i = n - 1; i > 0; i--) {
            printf("%d %d\n", cur, i);
            cur = (cur + i + 1) / 2;
        }
    }
    return 0;
}