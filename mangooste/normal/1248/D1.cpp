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

using ll = long long;
using namespace std;

namespace Debug {
    // #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> bal(n);
    bal[0] = (s[0] == '(' ? 1 : -1);
    for (int i = 1; i < n; i++)
        bal[i] = bal[i - 1] + (s[i] == '(' ? 1 : -1);
    if (bal.back() != 0)
        return cout << "0\n1 1\n", 0;
    vector<vector<int>> cnt(2 * n + 1);
    for (int i = 0; i < n; i++)
        cnt[bal[i] + n].push_back(i);
    for (int i = 0; i < 2 * n + 1; i++)
        debug(i - n, cnt[i]);
    int mn_bal = 0;
    while (cnt[mn_bal].size() == 0)
        mn_bal++;
    debug(bal);
    debug(mn_bal);
    int ans = cnt[mn_bal].size();
    int pos1 = 0, pos2 = 0;
    vector<pair<int, int>> right(n, {-1, -1}), left(n, {-1, -1});
    if (s[0] == '(')
        left[0].first = 0;
    else
        left[0].second = 0;
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1];
        if (s[i] == '(')
            left[i].first = i;
        else
            left[i].second = i;
    }
    if (s[n - 1] == '(')
        right[n - 1].first = n - 1;
    else
        right[n - 1].second = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1];
        if (s[i] == '(')
            right[i].first = i;
        else
            right[i].second = i;
    }
    debug(left);
    debug(right);
    vector<int> bad = {-1};
    for (auto i : cnt[mn_bal])
        bad.push_back(i);
    for (auto i : cnt[mn_bal + 1])
        bad.push_back(i);
    bad.push_back(n);
    sort(all(bad));
    debug(bad);
    for (int i = 1; i < bad.size(); i++) {
        int L = bad[i - 1] + 1, R = bad[i] - 1;
        if (L > R)
            continue;
        debug("was", L, R);
        L = right[L].first;
        R = left[R + 1].second;
        debug("cur", L, R);
        if (L > R || L == -1 || R == -1)
            continue;
        int cur_ans = cnt[mn_bal].size();
        cur_ans += lower_bound(all(cnt[mn_bal + 2]), R) - lower_bound(all(cnt[mn_bal + 2]), L);
        debug(cur_ans);
        if (cur_ans > ans)
            ans = cur_ans, pos1 = L, pos2 = R;
    }
    bad = {-1};
    for (auto i : cnt[mn_bal])
        bad.push_back(i);
    bad.push_back(n);
    for (int i = 1; i < bad.size(); i++) {
        int L = bad[i - 1] + 1, R = bad[i] - 1;
        if (L > R)
            continue;   
        L = right[L].first;
        R = left[R + 1].second;
        if (L > R || L == -1 || R == -1)
            continue;
        int cur_ans = lower_bound(all(cnt[mn_bal + 1]), R) - lower_bound(all(cnt[mn_bal + 1]), L);
        if (cur_ans > ans)
            ans = cur_ans, pos1 = L, pos2 = R;
    }
    int L = left[cnt[mn_bal][0]].second;
    int R = -1;
    if (cnt[mn_bal].back() != n - 1)
        R = right[cnt[mn_bal].back() + 1].first;
    if (L != -1 && R != -1 && L < R) {
        int cur_ans;
        if (cnt[mn_bal + 1].size() == 0 || (L <= cnt[mn_bal + 1][0] && cnt[mn_bal + 1].back() < R))
            cur_ans = cnt[mn_bal].size() + cnt[mn_bal + 2].size() - (lower_bound(all(cnt[mn_bal + 2]), R) - lower_bound(all(cnt[mn_bal + 2]), L));
        else
            cur_ans = cnt[mn_bal + 1].size() - (lower_bound(all(cnt[mn_bal + 1]), R) - lower_bound(all(cnt[mn_bal + 1]), L));
        if (cur_ans > ans)
            ans = cur_ans, pos1 = L, pos2 = R;
    }
    if (cnt[mn_bal + 1].size() != 0 && max(cnt[mn_bal].back(), cnt[mn_bal + 1].back()) != n - 1) {
        L = left[min(cnt[mn_bal][0], cnt[mn_bal + 1][0])].second;
        R = right[max(cnt[mn_bal].back(), cnt[mn_bal + 1].back()) + 1].first;
        int cur_ans = 0;
        if (L != -1 && R != -1 && L < R)
            cur_ans = cnt[mn_bal].size() + cnt[mn_bal + 2].size() - (lower_bound(all(cnt[mn_bal + 2]), R) - lower_bound(all(cnt[mn_bal + 2]), L));
        if (cur_ans > ans)
            ans = cur_ans, pos1 = L, pos2 = R;
    }
    cout << ans << '\n' << pos1 + 1 << ' ' << pos2 + 1 << '\n';
}