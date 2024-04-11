#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, p;

int main()
{
    cin >> n >> p;
    if (p == 0)
        cout << __builtin_popcountll(n) << endl;
    else if (p > 0) {
        for (int i = 1; ; i++) {
            ll lft = n - p * ll(i);
            if (lft < i) break;
            if (__builtin_popcountll(lft) <= i) {
                printf("%d\n", i); return 0;
            }
        }
        printf("-1\n");
    } else for (int i = 1; ; i++) {
        ll lft = n - p * ll(i);
        if (__builtin_popcount(lft) <= i && i <= lft) {
            printf("%d\n", i); return 0;
        }
    }
    return 0;
}