#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

char fl(char c) {
    if (c == '1') return '0';
    if (c == '0') return '1';
    return c;
}
int cnt(string s, char c) {
    int ret = 0;
    for (auto x: s) ret += (x == c);
    return ret;
}
int c[4005][4005];

int calc(int aone, int afree, int bone, int bfree) {
    int dif = aone - bone;
    int n = afree + bfree, k = afree + dif;
    int ans;
    if (k < 0 || k > n) ans = 0;
    else ans = c[n][k];
    //cout << aone << ' ' << afree << ' ' << bone << ' ' << bfree << ' ' << ans << '\n';
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    c[0][0] = 1;
    for (int i = 1; i <= 4000; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        for (int i = 1; i < n; i += 2) a[i] = fl(a[i]);
        for (int i = 1; i < n; i += 2) b[i] = fl(b[i]);
        int aone = cnt(a, '1');
        int afree = cnt(a, '?');
        int bone = cnt(b, '1');
        int bfree = cnt(b, '?');
        int ans = 0;
        int aonel = 0, afreel = 0, aoner = aone, afreer = afree;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') --aoner;
            if (a[i] == '?') --afreer;
            int bonel = 0, bfreel = 0, boner = bone, bfreer = bfree;
            for (int j = 0; j < n; ++j) {
                if (b[j] == '1') --boner;
                if (b[j] == '?') --bfreer;

                if (a[i] != '0' && b[j] != '0') {
                    int add = 1ll * abs(i - j) * calc(aonel, afreel, bonel, bfreel) % mod * calc(aoner, afreer, boner, bfreer) % mod;
                    //cout << i << ' ' << j << ' ' << add << '\n';
                    ans = (ans + add) % mod;
                }

                if (b[j] == '1') ++bonel;
                if (b[j] == '?') ++bfreel;
            }
            if (a[i] == '1') ++aonel;
            if (a[i] == '?') ++afreel;
        }
        cout << ans << '\n';
    }
    return 0;
}