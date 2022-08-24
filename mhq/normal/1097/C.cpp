#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
string s;
const int maxN = (int)1e6;
vector < int > neg[maxN], pos[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > all;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int mn_bal = 0;
        cin >> s;
        int cur_bal = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(') cur_bal++;
            else cur_bal--;
            mn_bal = min(mn_bal, cur_bal);
        }
        if (cur_bal < 0) neg[-cur_bal].push_back(mn_bal);
        else {
            if (mn_bal >= 0) pos[cur_bal].push_back(mn_bal);
        }
        if (mn_bal >= 0 && cur_bal == 0) zero++;
    }
    int ans = 0;
    for (int j = 1; j < maxN; j++) {
        int t = 0;
        for (int v : neg[j]) {
            if (v >= -j) t++;
        }
        ans += min((int)pos[j].size(), t);
    }
    ans += zero / 2;
    cout << ans;
    return 0;
}