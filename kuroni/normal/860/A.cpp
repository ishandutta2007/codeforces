#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 3005;

int n;
char s[N];
bool chk[N];
pair<int, int> f[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = {N, 0};
        int cnt = 0, msk = 0;
        for (int j = i; j >= 1; j--) {
            if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u') {
                ++cnt;
                msk |= (1 << (s[j] - 'a'));
                if (cnt >= 3 && __builtin_popcount(msk) > 1) {
                    break;
                }
            } else {
                cnt = msk = 0;
            }
            f[i] = min(f[i], {f[j - 1].fi + 1, j - 1});
        }
    }
    for (int i = n; i > 0; i = f[i].se) {
        chk[i] = true;
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i];
        if (chk[i]) {
            cout << " ";
        }
    }
}