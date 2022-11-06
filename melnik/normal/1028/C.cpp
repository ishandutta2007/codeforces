#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 150500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair <pair <int, int>, pair <int, int>> a[maxn];
vector <pair <int, int>> all_x, all_y;

vector <int> x_coond;
vector <int> y_coond;

bool Good(int x, int y, int n) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += (x >= a[i].f.f) & (x <= a[i].s.f) & (y >= a[i].f.s) & (y <= a[i].s.s);
    return cnt >= n - 1;
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d%d%d%d", &a[i].f.f, &a[i].f.s, &a[i].s.f, &a[i].s.s);
    for (int i = 0; i < n; ++i) {
        all_x.pb(mp(a[i].f.f, -1));
        all_x.pb(mp(a[i].s.f, 1));
        all_y.pb(mp(a[i].f.s, -1));
        all_y.pb(mp(a[i].s.s, 1));
    }
    sort(all_x.begin(), all_x.end());
    sort(all_y.begin(), all_y.end());
    assert(all_x.size() == all_y.size());
    int bal = 0;
    for (auto x : all_x) {
        bal -= x.s;
        if (bal >= n - 1)
            x_coond.pb(x.f);
    }
    bal = 0;
    for (auto x : all_y) {
        bal -= x.s;
        if (bal >= n - 1)
            y_coond.pb(x.f);
    }

    for (auto x : x_coond)
        for (auto y : y_coond)
            if (Good(x, y, n)) {
                cout << x << ' ' << y << endl;
                return 0;
            }
    return 0;
}