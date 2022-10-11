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
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<char, int>> st;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.eb(s[i], 1);
            continue;
        }
        if (st.back().first == s[i]) {
            st.back().second++;
            continue;
        }
        while (!st.empty() && st.back().second % 2 == 0 && st.back().first != s[i]) {
            cnt += st.back().second / 2;
            st.pop_back();
        }
        if (st.empty())
            st.eb(s[i], 1);
        else if (st.back().first != s[i]) {
            cnt += st.back().second / 2;
            st.back().second = 1;
            st.eb(s[i], 1);
        } else
            st.back().second++;
        // cerr << "i = " << i << " st = ";
        // for (auto el : st)
        //     cout << "(" << el.first << ' ' << el.second << ") ";
        // cout << '\n';
    }
    for (auto el : st)
        cnt += el.second / 2;
    cout << (cnt % 2 == 0 ? "No" : "Yes") << '\n';
}