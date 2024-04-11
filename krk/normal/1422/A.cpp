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
        ll res = ll(a) + ll(b) + ll(c) - 1ll;
        cout << res << endl;
    }
    return 0;
}