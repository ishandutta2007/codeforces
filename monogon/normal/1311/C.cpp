
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, m, p[N], cnt[26];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        fill(cnt, cnt + 26, 0);
        for(int i = 0; i < m; i++) {
            cin >> p[i];
        }
        sort(p, p + m);
        p[m] = n;
        for(int i = 0; i <= m; i++) {
            for(int j = (i == 0 ? 0 : p[i - 1]); j < p[i]; j++) {
                cnt[s[j] - 'a'] += m - i + 1;
            }
        }
        for(int i = 0; i < 26; i++) {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }
}