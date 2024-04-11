#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e4 + 10;
string s[maxN];
map < string, int > any;
map < string, int > cnt;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        map < string, bool > was;
        int m = s[i].size();
        for (int j = 0; j < m; j++) {
            for (int k = j; k < m; k++) {
                string t = s[i].substr(j, k - j + 1);
                if (was.count(t)) continue;
                was[t] = true;
                any[t] = i;
                cnt[t]++;
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string t;
        cin >> t;
        if (!cnt.count(t)) {
            cout << 0 << " " << "-" << '\n';
        }
        else {
            cout << cnt[t] << " " << s[any[t]] << '\n';
        }
    }
    return 0;
}