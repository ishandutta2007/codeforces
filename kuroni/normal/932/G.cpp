#include <bits/stdc++.h>
using namespace std;
    
const int N = 1E6 + 5, MOD = 1E9 + 7;
    
int n, f[N];
int cnt = 0, lst = 0, len[N], dif[N], lk[N], slk[N], g[N], ch[N][26];
char s[N], t[N];
    
int get_link(int lst, int i) {
    while (s[i - len[lst] - 1] != s[i]) {
        lst = lk[lst];
    }
    return lst;
}
    
void init() {
    n = strlen(t + 1);
    for (int i = 1; i <= n; i += 2) {
        s[i] = t[n / 2 + i / 2 + 1];
        s[i + 1] = t[n / 2 - i / 2];
    }
    lk[cnt++] = 1;
    len[cnt++] = -1;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (t + 1);
    init();
    f[0] = g[0] = g[1] = 1;
    for (int i = 1; i <= n; i++) {
        lst = get_link(lst, i);
        if (ch[lst][s[i] - 'a'] == 0) {
            len[cnt] = len[lst] + 2;
            lk[cnt] = ch[get_link(lk[lst], i)][s[i] - 'a'];
            dif[cnt] = len[cnt] - len[lk[cnt]];
            slk[cnt] = (dif[cnt] == dif[lk[cnt]] ? slk[lk[cnt]] : lk[cnt]);
            ch[lst][s[i] - 'a'] = cnt++;
        }
        lst = ch[lst][s[i] - 'a'];
        for (int suf = lst; len[suf] > 0; suf = slk[suf]) {
            g[suf] = f[i - dif[suf] - len[slk[suf]]];
            if (dif[suf] == dif[lk[suf]]) {
                (g[suf] += g[lk[suf]]) %= MOD;
            }
            (f[i] += g[suf]) %= MOD;
        }
        if (i & 1) {
            f[i] = 0;
        }
    }
    cout << f[n];
}