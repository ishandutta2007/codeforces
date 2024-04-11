#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        printf("%I64d %I64d\n", -(n - 1ll), n);
    }
    return 0;
}