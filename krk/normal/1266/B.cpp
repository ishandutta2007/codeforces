#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll x;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d", &x);
        bool ok = x >= 14 && 1 <= x % 14 && x % 14 <= 6;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}