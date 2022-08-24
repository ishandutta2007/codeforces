#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
string s;
int val[26];
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        val[s[i] - 'A']++;
    }
    int ans = s.size();
    for (int i = 0; i < k; i++) ans = min(ans, val[i]);
    cout << ans * k;
    return 0;
}