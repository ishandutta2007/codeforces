#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll s, n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d %I64d", &s, &n, &k);
        if (s < k) printf("NO\n");
        else if (s == k) printf("YES\n");
        else if (s >= n + (n / k) * k) printf("NO\n");
        else printf("YES\n"); 
    }
    return 0;
}