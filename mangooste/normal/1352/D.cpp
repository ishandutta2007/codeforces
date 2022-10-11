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

#define int long long
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
        cin >> n;
        vector<int> a(n);
        for (auto &el : a)
            cin >> el;
        int lft = 0, rgt = n - 1;
        int cnt = 0, as = 0, bs = 0;
        int la = 0, lb = 0;
        while (lft <= rgt) {
            int sm;
            cnt++;
            sm = 0;
            while (lft <= rgt && sm <= lb)
                sm += a[lft++];
            as += sm;
            la = sm;
            if (lft > rgt) 
                break;
            cnt++;
            sm = 0;
            while (rgt >= lft && sm <= la)
                sm += a[rgt--];
            bs += sm;
            lb = sm;
        }
        cout << cnt << ' ' << as << ' ' << bs << '\n';
    }
}