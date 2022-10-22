#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, m, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        int dist = 2000000000;
        if (m >= n - 1 && m <= ll(n) * (n - 1) / 2)
            if (n == 1) dist = 0;
            else if (n == 2 || ll(n) * (n - 1) / 2 == m) dist = 1;
            else dist = 2;
        printf("%s\n", dist < k - 1? "YES": "NO");
    }
    return 0;
}