#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        string need;
        for (int i = 0; i < k - 1; i++) need += "()";
        int lft = n - 2 * (k - 1);
        for (int i = 0; i < lft / 2; i++) need += "(";
        for (int i = 0; i < lft / 2; i++) need += ")";
        vector < pair < int, int > > ans;
        //cout << need << endl;
        for (int i = 0; i < need.size(); i++) {
            if (need[i] != s[i]) {
                for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] == need[i]) {
                        ans.emplace_back(i + 1, j + 1);
                        int l = i;
                        int r = j;
                        while (l < r) {
                            swap(s[l], s[r]);
                            l++;
                            r--;
                        }
                        break;
                    }
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto it : ans) cout << it.first << " " << it.second << '\n';
    }
    return 0;
}