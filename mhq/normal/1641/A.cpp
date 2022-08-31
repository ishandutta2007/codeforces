#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        map<ll,int> mp;
        for (int& v : a) {
            cin >> v;
            mp[v]++;
        }
        sort(a.begin(), a.end());
        int need = n;
        for (auto& it : a) {
            ll v = it;
            if (mp.count(v * x)) {
                int take = min(mp[v], mp[v * x]);
                mp[v] -= take;
                mp[v * x] -= take;
                need -= 2 * take;
            }
        }
        cout << need << '\n';
    }
    return 0;
}