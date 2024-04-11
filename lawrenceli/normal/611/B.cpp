#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 2; i < 63; i++)
        for (int j = 0; j < i - 1; j++) {
            ll x = (1LL << i) - (1LL << j) - 1;
            if (a <= x && x <= b) ans++;
        }

    cout << ans << '\n';
}