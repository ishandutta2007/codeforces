#include <bits/stdc++.h>
using namespace std;

int T;
int n, d;

bool Check(int n, int d)
{
    for (int i = 0; i <= 500000; i++)
        if (i + (d + i) / (i + 1) <= n) return true;
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &d);
        printf("%s\n", Check(n, d)? "YES": "NO");
    }
    return 0;
}