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

        vector<char> used(n, 0);
        map<int, vector<int>> mapa;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j)
                    continue;
                mapa[j].push_back(i);
                break;
            }
        }

        int free = 1;
        for (auto i : mapa) {
            bool was = false;
            for (auto j : i.second) {
                if (used[j])
                    continue;
                was = true;
                ans[j] = free;
                used[j] = 1;
            }
            if (was)
                free++;
        }

        cout << free - 1 << '\n';
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}