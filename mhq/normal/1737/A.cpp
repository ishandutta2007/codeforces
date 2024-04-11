#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        int sz = n / k;
        string t;
        for (int i = 0; i < k; i++) {
            int lst = sz;
            for (int j = 0; j < sz; j++) {
                if (cnt[j] < (i + 1)) {
                    lst = j;
                    break;
                }
            }
            t += (char)(lst + 'a');
        }
        cout << t << '\n';
    }
    return 0;
}