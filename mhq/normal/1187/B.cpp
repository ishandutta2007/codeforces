#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
const int maxN = 2 * (int)1e5 + 100;
int val[maxN][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        int num = 0;
        val[0][i] = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == (char)(i + 'a')) {
                num++;
                val[num][i] = j + 1;
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        string t;
        cin >> t;
        int need = 0;
        for (int k = 0; k < 26; k++) {
            int cnt = 0;
            for (char c : t) {
                cnt += (c == (char)(k + 'a'));
            }
            need = max(need, val[cnt][k]);
        }
        cout << need << '\n';
    }
    return 0;
}