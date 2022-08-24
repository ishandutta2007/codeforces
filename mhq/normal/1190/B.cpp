#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 100;
int a[maxN];
void debil1() {
    cout << "sjfnb";
    exit(0);
}
void debil2() {
    cout << "cslnb";
    exit(0);
}
int solve() {
    ll sz = 0;
    for (int i = 1; i <= n; i++) {
        assert(a[i] >= i - 1);
        sz += (a[i] - (i - 1));
    }
    return (sz % 2) ^ 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ind = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            ind = i;
        }
    }
    int x;
    if (ind == -1) {
        x = solve();
    }
    else {
        if (a[ind] == 0) {
            debil2();
        }
        else {
            a[ind]--;
            sort(a + 1, a + n + 1);
            bool bad = false;
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i + 1]) {
                    bad = true;
                    break;
                }
            }
            if (bad) debil2();
            else {
                x = solve() ^ 1;
            }
        }
    }
    if (x == 1) debil2();
    else debil1();
    return 0;
}