#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 70111;
const ld inf = 2000111000;
int x[max_n];
int v[max_n];
int n;

ld check(ld curx)
{
    ld curt;
    ld maxt = -1;
    for (int i = 0; i < n; ++i) {
        ld dx = abs(1.0 * x[i] - curx);
        curt = 1.0 * dx  / v[i];
        maxt = max(maxt, curt);
    }
    return maxt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ld l = -inf, r = inf;
    for (int i = 0; i < 120; ++i) {
        ld mid1 = l + (r - l) / 3;
        ld mid2 = l + 2 * (r - l) / 3;
        if (check(mid1) > check(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    cout << fixed << setprecision(10) << check(l);
    return 0;
}