#include <bits/stdc++.h>
using namespace std;
const int maxN = 3 * (int)1e5 + 10;
int n, x, y;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> x >> y;
    cin >> s;
    bool zero = false;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            zero = false;
        }
        else {
            if (zero) continue;
            else {
                zero = true;
                cnt++;
            }
        }
    }
    if (cnt == 0) cout << 0;
    else cout << min(1LL * cnt * y, 1LL * (cnt - 1) * x + 1LL * y);
	return 0;
}