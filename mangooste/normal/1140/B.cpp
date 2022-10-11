#include <algorithm>
#include <cassert>
#include <cmath>
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = n - 1;
        for (int i = 0; i < n; i++)
            if (s[i] == '>')
                ans = min(ans, i);
        for (int i = 0; i < n; i++)
            if (s[n - 1 - i] == '<')
                ans = min(ans, i);
        cout << ans << '\n';
    }
}