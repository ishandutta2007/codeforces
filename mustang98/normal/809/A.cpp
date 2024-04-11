#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222, mod = 1000000007;

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(m, m + n);
    ll dv = 0, ans = 0, last = 0;
    for (int i = 1; i < n; ++i) {
        ll delta = m[i] - m[i - 1];
        last = (last * 2);
        dv = dv * 2 + 1;
        last += dv * delta;
        ans += last;
        ans %= mod;
        dv %= mod;
        last %= mod;
    }
    cout << ans;
    return 0;
}