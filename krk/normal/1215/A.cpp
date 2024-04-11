#include <bits/stdc++.h>
using namespace std;

int a1, a2;
int k1, k2;
int a;

int main()
{
    cin >> a1 >> a2;
    cin >> k1 >> k2;
    if (k1 > k2) { swap(a1, a2); swap(k1, k2); }
    cin >> a;
    int tk = min(a1, a / k1);
    int mx = tk + min(a2, (a - tk * k1) / k2);
    int got = a1 * (k1 - 1) + a2 * (k2 - 1);
    int mn = max(0, a - got);
    cout << mn << " " << mx << endl;
    return 0;
}