#include <bits/stdc++.h>
using namespace std;

int mx;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        a += mx;
        mx = max(mx, a);
        printf("%d%c", a, i + 1 < n? ' ': '\n');
    }
    return 0;
}