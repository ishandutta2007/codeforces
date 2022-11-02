#include <bits/stdc++.h>

using namespace std;

const int maxn = 1505;

int n, q;
char s[maxn];
int ans[maxn][26];
int freq[26];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        memset(freq, 0, sizeof(freq));
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            freq[s[j] - 'a']++;
            for (int k = 0; k < 26; k++)
                ans[len - freq[k]][k] = max(ans[len - freq[k]][k], len);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            ans[i + 1][j] = max(ans[i + 1][j], ans[i][j]);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int x; char c;
        cin >> x >> c;
        cout << ans[x][c - 'a'] << '\n';
    }
}