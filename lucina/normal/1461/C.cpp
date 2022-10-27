#include<bits/stdc++.h>
using namespace std;
int const N = 3e5 + 10;
pair <int, double> b[N];
int n, m;
int a[N];
double pref[N];
double suf[N];
double bar[N];
double u[N];

vector <double> c[N];
vector <double> d[N];

void solve() {
    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    int max_sort = n + 1;

    for (int i = n ; i >= 1 ; -- i) {
        if (a[i] != i) break;
        max_sort = i;
    }

    int ev = 0;
    double no_choose_at_all = 1.0;

    for (int i = 1 ; i <= n + 3 ; ++ i) {
        c[i].clear();
        d[i].clear();
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] != i) break;
        b[++ ev] = make_pair(i, 1.0);
    }

    for (int i = 1 ; i <= m ; ++ i) {
        ++ ev;
        int x;
        double y;
        cin >> x >> y;
        b[ev] = make_pair(x, y);
        c[x].push_back(y);
        d[x].push_back(1.0 - y);
        no_choose_at_all *= 1.0 - y;
    }

    double ff = 1.0;
    u[n + 1] = 1.0;

    for (int i = n ; i >= 1 ; -- i) {
        for (auto foo : d[i]) {
            ff *= foo;
        }
        u[i] = ff;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        bar[i] = 1.0;
        for (auto foo : d[i])
            bar[i] *= foo;
    }

    double ans = 0.0;

    for (int i = 1 ; i <= n ; ++ i) {
        double this_choose = 1.0 - bar[i];
        double non_choose = u[i + 1];
        this_choose *= non_choose;
        //cout << this_choose << '\n';
        if (max_sort <= i + 1) ans += this_choose;
    }

    if (max_sort == 1) ans += no_choose_at_all;

    cout << ans << '\n';



}

int main() {
    cout.precision(10);
    cout << fixed;
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}