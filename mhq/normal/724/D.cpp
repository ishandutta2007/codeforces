#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int cnt[26];
string s;
int m;
bool can(int l, int r, int symb) {
    if (r - l + 1 < m) return true;
    int pos = l;
    while (pos <= r) {
        if (pos + m - 1 > r) return true;
        int where = -1;
        for (int i = pos + m - 1; i >= pos; i--) {
            if (s[i] == (char)(symb + 'a')) {
                where = i;
                break;
            }
        }
        if (where == -1) {
            return false;
        }
        pos = where + 1;
    }
    return true;
}
int smallest(int l, int r, int symb) {
    if (r - l + 1 < m) return 0;
    int pos = l;
    int cnt = 0;
    while (pos <= r) {
        if (pos + m - 1 > r) return cnt;
        int where = -1;
        for (int i = pos + m - 1; i >= pos; i--) {
            if (s[i] == (char)(symb + 'a')) {
                where = i;
                break;
            }
        }
        cnt++;
        pos = where + 1;
    }
    return cnt;
}
vector < pair < int, int > > solve(int l, int r, int symb) {
    vector < int > all_pos;
    all_pos.push_back(l - 1);
    for (int i = l; i <= r; i++) {
        if (s[i] == (char)(symb + 'a')) {
            cnt[symb]++;
            all_pos.push_back(i);
        }
    }
    all_pos.push_back(r + 1);
    vector < pair < int, int > > ans;
    for (int j = 0; j + 1 < all_pos.size(); j++) {
        ans.emplace_back(all_pos[j] + 1, all_pos[j + 1] - 1);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> m >> s;
    vector < pair < int, int > > hs = {make_pair(0, s.size() - 1)};
    for (int i = 0; i < 26; i++) {
        bool all_ok = true;
        for (auto it : hs) {
            if (!can(it.first, it.second, i)) {
                all_ok = false;
                break;
            }
        }
        if (all_ok) {
            for (auto it : hs) {
                cnt[i] += smallest(it.first, it.second, i);
            }
            break;
        }
        vector < pair < int, int > > new_hs;
        for (auto it : hs) {
            auto gt = solve(it.first, it.second, i);
            for (auto p : gt) {
                if (p.first <= p.second) new_hs.emplace_back(p);
            }
        }
        hs = new_hs;
    }
    for (int i = 0; i < 26; i++) {
        cout << string(cnt[i], 'a' + i);
    }
    return 0;
}