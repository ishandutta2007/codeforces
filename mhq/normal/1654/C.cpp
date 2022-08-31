#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        ll s = 0;
        map<ll,int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            mp[a[i]]++;
        }
        queue<ll> q;
        q.push(s);
        bool ok = true;
        int cur_sz = 1;
        while (!q.empty()) {
            ll f = q.front();
            q.pop();
            if (mp.count(f) && mp[f] > 0) {
                mp[f]--;
                continue;
            }
            cur_sz++;
            if (cur_sz > n) {
                cout << "NO\n";
                ok = false;
                break;
            }
            if (f == 1) {
                cout << "NO\n";
                ok = false;
                break;
            }
            q.push(f / 2);
            q.push((f + 1) / 2);
        }
        if (ok) cout << "YES\n";
    }

    return 0;
}