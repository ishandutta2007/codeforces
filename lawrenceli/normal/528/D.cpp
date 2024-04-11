#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int n, m, k, add[MAXN];
char s[MAXN], t[MAXN];
bitset<MAXN> ans;

int conv(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k >> s >> t;
    for (int i=0; i<n; i++) s[i] = conv(s[i]);
    for (int i=0; i<m; i++) t[i] = conv(t[i]);

    for (int i=0; i<n; i++) ans[i] = 1;

    for (int x=0; x<4; x++) {
        memset(add, 0, sizeof(add));
        for (int i=0; i<n; i++)
            if (s[i] == x) {
                add[max(0, i-k)]++;
                add[min(n, i+k+1)]--;
            }

        bitset<MAXN> y;
        for (int i=0, j=0; i<n; i++) {
            j += add[i];
            y[i] = bool(j);
        }

        for (int i=0; i<m; i++)
            if (t[i] == x)
                ans &= y>>i;
    }

    cout << ans.count();
}