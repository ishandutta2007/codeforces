#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
int m;
ll k;
const int maxN = (int)1e5 + 100;
ll p[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
        p[i]--;
    }
    int who = 1;
    ll ans = 0;
    ll add = 0;
    while (who <= m) {
        add += ((p[who] - add) / k) * k;
        ans++;
        int was = who;
        while (p[who] < add + k) who++;
        add += who - was;
    }
    cout << ans;
    return 0;
}