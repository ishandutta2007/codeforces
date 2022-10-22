#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll a, b, n, m;

int main()
{
    cin >> T;
    while (T--) {
        cin >> a >> b >> n >> m;
        if (m <= min(a, b) && n + m <= a + b)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}