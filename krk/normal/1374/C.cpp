#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int cur = 0, mn = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '(') cur++;
            else { cur--; mn = min(mn, cur); }
        printf("%d\n", -mn);
    }
    return 0;
}