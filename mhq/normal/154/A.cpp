#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;

bool has[30][30];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        char x, y;
        cin >> x >> y;
        has[x - 'a'][y - 'a'] = has[y - 'a'][x - 'a'] = true;
    }
    int i = 0;
    int ans = 0;
    while (i < s.size()) {
        int j = i;
        while ((j < s.size()) && (s[j] == s[i] || has[s[j] - 'a'][s[i] - 'a'])) j++; j--;
        int f0 = 0, f1 = 0;
        for (int t = i; t <= j; t++) {
            if (s[t] == s[i]) f0++;
            else f1++;
        }
        ans += min(f0, f1);
        i = j + 1;

    }
    cout << ans;
    return 0;
}