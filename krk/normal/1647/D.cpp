#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int x, d;

bool primeOrOne(int x)
{
    if (x <= 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &d);
        int cnt = 0;
        while (x % d == 0) {
            cnt++;
            x /= d;
        }
        if (primeOrOne(d))
            if (cnt == 1) printf("NO\n");
            else printf("%s\n", primeOrOne(x)? "NO": "YES");
        else if (cnt == 1) printf("NO\n");
             else if (cnt == 2) printf("%s\n", primeOrOne(x)? "NO": "YES");
             else if (cnt == 3) printf("%s\n", primeOrOne(x) && ll(x) * x == d? "NO": "YES");
             else printf("YES\n");
    }
    return 0;
}