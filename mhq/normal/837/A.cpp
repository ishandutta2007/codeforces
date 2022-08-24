#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    int mx = 0;
    int tr;
    cin >> tr;
    while (cin >> s) {
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= 'A' && s[j] <= 'Z') cnt++;
        }
        mx = max(mx, cnt);
    }
    cout << mx;
    return 0;
}