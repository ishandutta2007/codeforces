#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1111, inf = 1000111222;

int n;
ld m;
ll a[max_n];
ll b[max_n];

bool check(ld top) {
    for (int i = 0; i < n; ++i) {
        ld waste = (m + top) / a[i % n];
        top -= waste;
        if (top < 0) return 0;
        waste = (m + top) / b[(i + 1) % n];
        top -= waste;
        if (top < 0) return 0;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ld inf = 1e10;
    ld l = 0, r = inf;
    for (int i = 0; i < 1000; ++i) {
        ld mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r > 1e9 + 100) {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(10) << l;
    return 0;
}