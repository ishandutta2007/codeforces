#include <bits/stdc++.h>

using namespace std;
int n, m;
const int maxN = 1005;
typedef long double ld;
int cnt[maxN];
mt19937 rnd(322);
uniform_real_distribution<ld> cc(0, 1.0);
int main() {
    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        int mn = 1e9;
        for (int x = 0; x < n; x++) {
            mn = min(mn, cnt[x]);
        }
        int a = 0;
        int b = 0;
        ld A = 0;
        ld B = 0;
        for (int x = 0; x < s.size(); x++) {
            if (s[x] == '0') {
                A += powl(2, -cnt[x] - 1);
            }
            else {
                B += powl(2, -cnt[x] - 1);
                //B += (1.0) / ((ld)(cnt[x] + 1) * (cnt[x] + 1));
            }
        }
        int resp;
        if (cc(rnd) < A / (A + B)) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
        cin >> resp;
        for (int x = 0; x < n; x++) {
            if ((int)(s[x] - '0') != resp) {
                cnt[x]++;
            }
        }
    }
    return 0;
}