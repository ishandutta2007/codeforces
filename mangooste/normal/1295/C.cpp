#include <iostream>
#include <string>
#include <vector>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        string t;
        cin >> s >> t;
        int n = (int)s.size();
        int m = (int)t.size();
        vector <vector <int>> right(n, vector <int> (26, -1));
        right.back()[(int)(s.back() - 'a')] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1];
            right[i][(int)(s[i] - 'a')] = i;
        }
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (right[0][(int)(t[i] - 'a')] == -1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        int j = 0;
        int res = 1;
        for (int i = 0; i < m; i++) {
            if (j >= n) {
                res++;
                j -= n;
            }
            int cur = (int)(t[i] - 'a');
            if (right[j][cur] == -1) {
                res++;
                j = right[0][cur];
            } else {
                j = right[j][cur];
            }
            j++;
        }
        cout << res << '\n';
    }
}