#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for (int j = 2; j * j <= k; j++)
    if (k % j == 0) {
        cout << j << k/j;
        return 0;
    }
    return 0;
}