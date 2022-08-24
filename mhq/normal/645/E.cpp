#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int lst[26];
const int mod = (int)1e9 + 7;
int f[2 * (int)1e6 + 10];
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cin >> s;
    f[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        //if (i == 1) cout << lst[s[i] - 'a'];
        if (lst[s[i] - 'a'] != 0) f[i + 1] = sub(mult(2, f[i]), f[lst[s[i] - 'a'] - 1]);
        else f[i + 1] = mult(2, f[i]);
        lst[s[i] - 'a'] = i + 1;
    }
    int m = s.size();
    for (int j = 1; j <= n; j++) {
        int mi = 2 * (int)1e6 + 10;
        int ind = -1;
        for (int i = 0; i < k; i++) {
            if (lst[i] < mi) {
                mi = lst[i];
                ind = i;
            }
        }
        if (mi == 0) f[m + j] = mult(2, f[m + j - 1]);
        else {
            f[m + j] = sub(mult(2, f[m + j - 1]), f[mi - 1]);
        }
        lst[ind] = m + j;
    }
    cout << f[m + n];
    return 0;
}