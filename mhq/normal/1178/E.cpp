#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = n - 1;
    string half1, half2;
    while (true) {
        if (l + 3 <= r) {
            bool ok = false;
            for (int i1 = 0; i1 <= 1; i1++) {
                if (ok) break;
                for (int i2 = 0; i2 <= 1; i2++) {
                    if (ok) break;
                    if (s[l + i1] == s[r - i2]) {
                        half1 += s[l + i1];
                        half2 += s[r - i2];
                        ok = true;
                        break;
                    }
                }
            }
            assert(ok);
            l += 2;
            r -= 2;
            continue;
        }
        else {
            if (l <= r) half1 += s[l];
            break;
        }
    }
    assert(half1.size() + half2.size() >= n / 2);
    reverse(half2.begin(), half2.end());
    cout << half1 << half2;
    return 0;
}