#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    vector<int> a;
    while (n != 0) {
        a.pb(n % 10);
        ans *= n % 10;
        n /= 10;
    }
    reverse(all(a));
    if (a.size() != 1) {
        int sz = a.size();
        int maybe = 1;
        for (int i = 0; i < sz - 1; i++)
            maybe *= 9;
        ans = max(ans, maybe);
        for (int i = 0; i < sz; i++) {
            int p = 1;
            if (i != 0 && a[i] == 0 && a[i - 1] == 0)
                continue;
            if (i == 0 && a[i] == 1)
                continue;
            if (a[i] == 0) {
                p *= a[i - 1] - 1;
                for (int j = i - 2; j >= 0; j--)
                    p *= a[j];
                for (int j = i + 1; j < sz; j++)
                    p *= 9;
                ans = max(ans, p);
            } else {
                for (int j = i - 1; j >= 0; j--) 
                    p *= a[j];
                p *= a[i] - 1;
                for (int j = i + 1; j < sz; j++)
                    p *= 9;
                ans = max(ans, p);
            }
        }
    }
    cout << ans << '\n';
}