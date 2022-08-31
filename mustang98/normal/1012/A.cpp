#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int m[max_n];

ll ans = 1LL * inf * inf;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    n *= 2;
    if (n == 2) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    sort(m, m + n);
    ll minx = m[0];
    ll maxx, maxy, miny;
    for (int i = n / 2 - 1; i < n; ++i) {
        maxx = m[i];
        if (maxx < m[n - 1]) {
            maxy = m[n - 1];
            if (i == n / 2 - 1) {
                miny = m[n / 2];
            } else {
                miny = m[n / 2 - 1];
            }
            ll curans = (maxx - minx) * (maxy - miny);
            ans = min(ans, curans);

        } else {
            for (int j = 1; j < n / 2; ++j) {
                miny = m[j];
                maxy = m[j + n / 2 - 1];
                ll curans = (maxx - minx) * (maxy - miny);
                ans = min(ans, curans);
            }
            break;
        }
    }

    cout << ans;
    return 0;
}