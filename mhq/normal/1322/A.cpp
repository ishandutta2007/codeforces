#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
string s;
const int maxN = (int)1e6 + 10;
int bal[maxN];
bool f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        bal[i + 1] = bal[i];
        if (s[i] == '(') bal[i + 1]++;
        else bal[i + 1]--;
    }
    if (bal[n] != 0) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = bal[i] < 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f[i]) cnt++;
        if (f[i] && !f[i + 1]) cnt++;
    }
    cout << cnt;
    return 0;
}