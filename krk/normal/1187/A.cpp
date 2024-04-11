#include <bits/stdc++.h>
using namespace std;

int T;
int n, s, t;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &s, &t);
        int c = s + t - n;
        printf("%d\n", max(s, t) - c + 1);
    }
    return 0;
}