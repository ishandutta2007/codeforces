#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int cost = n * a;
        if (b >= 0) cost += n * b;
        else {
            int cnt0 = 0;
            int cnt1 = 0;
            for (int i = 0; i < s.size(); i++) {
                if (i == 0 || s[i] != s[i - 1]) {
                    if (s[i] == '0') cnt0++;
                    else cnt1++;
                }
            }
            cost += (min(cnt0, cnt1) + 1) * b;
        }
        cout << cost << '\n';
    }
}