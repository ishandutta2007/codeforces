#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
const int maxN = 2 * (int)1e5 + 100;
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int bal1 = 0;
    int bal2 = 0;
    int n;
    cin >> n;
    //int mx = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        //mx = max({mx, bal1, bal2});
        if (c == '(') {
            if (bal1 > bal2) {
                bal2 += 1;
                cout << 1;
            }
            else {
                bal1 += 1;
                cout << 0;
            }
        }
        else {
            if (bal1 > bal2) {
                bal1 -= 1;
                cout << 0;
            }
            else {
                bal2 -= 1;
                cout << 1;
            }
        }
    }
    //cout << endl << mx;
    return 0;
}