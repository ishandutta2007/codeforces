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
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string ans = "";
        ans.pb('z' + 1);
        int k_ans = -1;
        for (int k = 0; k < n; k++) {
            string cur = "";
            for (int i = k; i < n; i++)
                cur.pb(s[i]);
            if (cur.size() % 2 == 1)
                for (int i = k - 1; i >= 0; i--)
                    cur.pb(s[i]);
            else
                for (int i = 0; i < k; i++)
                    cur.pb(s[i]);
            if (cur < ans)
                ans = cur, k_ans = k;
        }
        cout << ans << '\n' << k_ans + 1 << '\n';
    }
}