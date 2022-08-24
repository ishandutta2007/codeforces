#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 10;
string s[maxN], t[maxN];
int msk[maxN];
map < int, vector < int > > mp;
vector < vector < int > > ans;
void solve(int i, vector < int > all) {
    map < string, vector < int > > cls;
    for (int v : all) {
        string cur = s[v];
        while (!cur.empty()) {
            int lst = cur.back() - 'a';
            if (i & (1 << lst)) {
                cur.pop_back();
            }
            else {
                break;
            }
        }
        cls[cur].push_back(v);
    }
    for (auto it : cls) {
        ans.push_back(it.second);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
        for (int j = 0; j < t[i].size(); j++) {
            msk[i] |= (1 << (t[i][j] - 'a'));
        }
        mp[msk[i]].push_back(i);
    }
    for (auto it : mp) {
        solve(it.first, it.second);
    }
    cout << ans.size() << '\n';
    for (auto t : ans) {
        cout << t.size() << " ";
        for (int v : t) cout << v << " ";
        cout << '\n';
    }
    return 0;
}