#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ones = 0, zers = 0;
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (a == 1) ones++;
            else if (a == 0) zers++;
        }
        ll res = ones;
        while (zers--) res *= 2;
        cout << res << "\n";
    }
    return 0;
}