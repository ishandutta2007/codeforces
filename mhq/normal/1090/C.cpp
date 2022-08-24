#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = (int)3e5;
int sz[N];
set<int> pr[N];
vector<int> lst[N];
struct shit {
    int from, to, kind;
    shit(int from, int to, int kind): from(from), to(to), kind(kind) {

    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        int k, x;
        cin >> k;
        s += k;
        for (int j = 1; j <= k; j++) {
            cin >> x;
            sz[i]++;
            pr[i].insert(x);
            lst[x].push_back(i);
        }
    }
    int x = s / n;
    int y = s / n;
    if (s % n != 0) y++;
    vector<shit> ans;
    set<int> st, eq;
    for (int i = 1; i <= n; i++) {
        if (sz[i] < x) {
            st.insert(i);
        }
        if (sz[i] == x) {
            eq.insert(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        vector<int> bs, be;
        for (auto cur: lst[i]) {
            if (st.find(cur) != st.end()) {
                st.erase(cur);
                bs.push_back(cur);
            }
        }
        for (auto cur: lst[i]) {
            if (sz[cur] > y) {
                if (!st.empty()) {
                    auto it = st.begin();
                    ans.emplace_back(shit(cur, *it, i));
                    sz[*it]++;
                    sz[cur]--;
                    if (sz[*it] == x) {
                        eq.insert(*it);
                        st.erase(it);
                    } else {
                        bs.push_back(*it);
                        st.erase(it);
                    }
                }
            }
        }
        for (auto cur: bs) {
            st.insert(cur);
        }
    }
    for (int i = 1; i <= m; i++) {
        lst[i].clear();
    }
    for (auto tmp: ans) {
        pr[tmp.from].erase(tmp.kind);
        pr[tmp.to].insert(tmp.kind);
    }
    int l = ans.size();
    for (int i = 1; i <= n; i++) {
        for (auto j: pr[i]) {
            lst[j].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        vector<int> bs, be;
        for (auto cur: lst[i]) {
            if (eq.find(cur) != eq.end()) {
                eq.erase(cur);
                be.push_back(cur);
            }
        }
        for (auto cur: lst[i]) {
            if (sz[cur] > y) {
                if (!eq.empty() && x + 1 < sz[cur]){
                    auto it = eq.begin();
                    ans.emplace_back(shit(cur, *it, i));
                    sz[cur]--;
                    sz[*it]++;
                    eq.erase(it);
                }
            }
        }
        for (auto cur: be) {
            eq.insert(cur);
        }
    }
    for (int i = 1; i <= m; i++) {
        lst[i].clear();
    }
    for (int i = l; i < ans.size(); i++) {
        auto tmp = ans[i];
        pr[tmp.from].erase(tmp.kind);
        pr[tmp.to].insert(tmp.kind);
    }
    for (int i = 1; i <= n; i++) {
        for (auto j: pr[i]) {
            lst[j].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        vector<int> bs, be;
        for (auto cur: lst[i]) {
            if (st.find(cur) != st.end()) {
                st.erase(cur);
                bs.push_back(cur);
            }
        }
        for (auto cur: lst[i]) {
            if (sz[cur] == y) {
                if (!st.empty()) {
                    auto it = st.begin();
                    ans.emplace_back(shit(cur, *it, i));
                    sz[*it]++;
                    sz[cur]--;
                    if (sz[*it] == x) {
                        st.erase(it);
                    } else {
                        bs.push_back(*it);
                        st.erase(it);
                    }
                }
            }
        }
        for (auto cur: bs) {
            st.insert(cur);
        }
    }
    cout << ans.size() << "\n";
    for (auto tmp: ans) {
        cout << tmp.from << " " << tmp.to << " " << tmp.kind << "\n";
    }
    return 0;
}