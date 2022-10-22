#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, x, t;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &t);
        int mn = min(t / x, n - 1);
        ll sum = ll(mn + 1) * mn / 2;
        cout << sum + ll(mn) * (n - (mn + 1)) << endl;
    }
    return 0;
}