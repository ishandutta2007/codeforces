#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i : a)
            cin >> i;
        map<int, int> mapa;
        for (int i : a) {
            if (i & 1)
                continue;
            int cnt = 0;
            while ((i & 1) == 0)
                cnt++, i >>= 1;
            mapa[i] = max(mapa[i], cnt);
        }
        int ans = 0;
        for (auto i : mapa)
            ans += i.second;
        cout << ans << '\n';
    }
}