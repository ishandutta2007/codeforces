#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    set<string> setik;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                string cur = "";
                cur.push_back('a' + i);
                cur.push_back('a' + j);
                cur.push_back('a' + k);
                setik.insert(cur);
            }
        }
    }
    assert((int)setik.size() >= n);
    vector<string> start;
    while ((int)start.size() < n) {
        start.push_back(*setik.begin());
        setik.erase(setik.begin());
    }
    vector<string> finish(n, "");
    for (int pos = 0; pos < 3; pos++) {
        string cur = "";
        for (int i = 0; i < n; i++) {
            cur.push_back(start[i][pos]);
        }
        cout << "? " << cur << endl;
        cin >> cur;
        for (int i = 0; i < n; i++) {
            finish[i].push_back(cur[i]);
        }
    }
    map<string, int> where;
    for (int i = 0; i < n; i++) {
        where[start[i]] = i;
    }
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        assert(where.find(finish[i]) != where.end());
        to[i] = where[finish[i]];
    }
    string ans(n, 'a');
    for (int i = 0; i < n; i++) {
        ans[to[i]] = s[i];
    }
    cout << "! " << ans << endl;
}