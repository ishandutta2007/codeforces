#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll min_ost = 1LL * inf * inf;
    int ans = -1;
    for (int i = 0; i < k; ++i) {
        cin >> m[i];
        if (n % m[i] < min_ost) {
            min_ost = n % m[i];
            ans = i;
        }
    }
    cout << ans + 1 << ' ' << (n / m[ans]);
    return 0;
}