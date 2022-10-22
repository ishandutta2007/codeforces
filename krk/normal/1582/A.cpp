#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        ll res = ll(a) + ll(b) * 2ll + ll(c) * 3ll;
        cout << res % 2 << "\n";
    }
    return 0;
}