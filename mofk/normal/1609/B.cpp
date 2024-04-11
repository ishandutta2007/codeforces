#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;
int cnt[100005];
int f[4];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') ++cnt[i + 2];
        if (s[i] == 'b') ++cnt[i + 1];
        if (s[i] == 'c') ++cnt[i];
    }
    for (int i = 0; i < n + 2; ++i) ++f[cnt[i]];
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        --i;
        for (int j = i; j < i + 3; ++j) --f[cnt[j]];
        if (s[i] == 'a') --cnt[i + 2];
        if (s[i] == 'b') --cnt[i + 1];
        if (s[i] == 'c') --cnt[i];
        s[i] = c;
        if (s[i] == 'a') ++cnt[i + 2];
        if (s[i] == 'b') ++cnt[i + 1];
        if (s[i] == 'c') ++cnt[i];
        for (int j = i; j < i + 3; ++j) ++f[cnt[j]];
        cout << f[3] << '\n';
    }
    return 0;
}