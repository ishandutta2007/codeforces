#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 61;

int my[Maxb];
ll a, b;

int main()
{
    cin >> a >> b;
    if (a > b) { cout << "-1\n"; return 0; }
    for (int i = 0; i < Maxb; i++)
        if (a & 1ll << ll(i)) my[i]++;
    b -= a;
    for (int i = 0; i < Maxb; i++)
        if (b & 1ll << ll(i)) my[i]++;
    for (int i = Maxb - 1; i >= 0; i--)
        if (bool(my[i] % 2) != bool(a & 1ll << ll(i))) {
            my[i]--;
            if (i == 0) { cout << "-1\n"; return 0; }
            my[i - 1] += 2;
        }
    int mx = 0;
    for (int i = 0; i < Maxb; i++)
        mx = max(mx, my[i]);
    printf("%d\n", mx);
    for (int i = 0; i < mx; i++) {
        ll a = 0;
        for (int j = 0; j < Maxb; j++)
            if (my[j] > 0) { a |= 1ll << ll(j); my[j]--; }
        printf("%I64d%c", a, i + 1 < mx? ' ': '\n');
    }
    return 0;
}