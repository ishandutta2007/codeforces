#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;
ld inf = 1e18;

int a[max_n];
int b[max_n];
int n, p;

bool check(ld t) {
    ld needp = 0;
    for (int i = 0; i < n; ++i) {
        ld spend = a[i] * t;
        if (b[i] < spend) {
            needp += (spend - b[i]);
        }
    }
    ld can = t * p;
    return can >= needp;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll sumsp = 0;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", a + i, b + i);
        //a[i] = 1;
        //b[i] = 100000;
        sumsp += a[i];
    }
    ld l = 0;
    ld r = inf;
    for (int i = 0; i < 211; ++i) {
        ld mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r == inf || l > 1e11) {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(8) << l;
    return 0;
}