#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll x, y;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d %I64d", &x, &y);
        if (x == y + 1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}