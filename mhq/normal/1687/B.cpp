#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int ask(string s) {
    cout << "? " << s << endl;
    int resp;
    cin >> resp;
    return resp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector<pair<int,int>> costs;
    for (int i = 0; i < m; i++) {
        string s(m, '0');
        s[i] = '1';
        int d = ask(s);
        costs.emplace_back(d, i);
    }
    sort(costs.begin(), costs.end());
    int cur = 0;
    string ans(m, '0');
    for (auto& it : costs) {
        ans[it.second] = '1';
        int new_cur = ask(ans);
        if (new_cur == cur + it.first) {
            cur = new_cur;
        }
        else {
            ans[it.second] = '0';
        }
    }
    cout << "! " << cur << endl;
    return 0;
}