#include <bits/stdc++.h>

#define F first
#define S second
#define prev privet1

using namespace std;
typedef long long ll;

const int max_n = 100009;

int main()
{
    int n = 0, a = 0, b = 0;
    int m[max_n];
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int k256, k32;
    k256 = min(k5, min(k6, k2));
    k2 = k2 - k256;
    k32 = min(k2, k3);
    ll ans = 256LL * k256 + 32LL * k32;
    cout << ans;
    return 0;
}