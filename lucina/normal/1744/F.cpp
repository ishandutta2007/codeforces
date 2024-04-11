#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int n;
int a[nax];
int pos[nax];
int l[nax], r[nax];

void solve() {
    /**
        brute force for mex = 1, 2, ......
        if mex = x
        it means that 0 1 ... x - 1 must be in the range
        this can be used to cover any range with length
        x -> 2x
        Overcount?
    */

    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int cl = pos[0], cr = pos[0];
    l[0] = cl, r[0] = cl;
    for (int i = 1 ; i < n ; ++ i) {
        cl = min(cl, pos[i]);
        cr = max(cr, pos[i]);
        l[i] = cl, r[i] = cr;
    }
    int64_t ans = 0;

    for (int ln = 1 ; ln <= n ; ++ ln) {
        int need = (ln - 1) / 2;
        if (ln < r[need] - l[need] + 1) continue;
        int can_start = max(0, r[need] - ln + 1);
        int max_go = n - ln;
        int f = min(l[need], max_go) - can_start + 1;
        ans += max(0, f);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}