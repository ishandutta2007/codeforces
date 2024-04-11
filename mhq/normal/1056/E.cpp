#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e6 + 10;
const int mod[] = {(int)1e9 + 7, (int)1e9 + 9, 998244353};
int sum(int a, int b, int mod) {
    int s = a + b;
    if (s >= mod) {
        s -= mod;
    }
    return s;
}
int sub(int a, int b, int mod) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}
int pw[3][maxN];
int hsh[3][maxN];
string s, t;
bool check_equal(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    for (int j = 0; j < 3; j++) {
        int hsh1 = hsh[j][r1];
        if (l1 - 1 >= 0) hsh1 = sub(hsh1, hsh[j][l1 - 1], mod[j]);
        int hsh2 = hsh[j][r2];
        if (l2 - 1 >= 0) hsh2 = sub(hsh2, hsh[j][l2 - 1], mod[j]);
        if (mult(hsh1, pw[j][l2 - l1], mod[j]) != hsh2) return false;
    }
    return true;
}
bool go(int len0, int len1) {
    vector < pair < int, int > > ones;
    vector < pair < int, int > > zeroes;
    int i = 0;
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == '0') {
            zeroes.emplace_back(i, i + len0 - 1);
            i += len0;
        }
        else {
            ones.emplace_back(i, i + len1 - 1);
            i += len1;
        }
    }
    bool can = true;
    for (int k = 1; k < zeroes.size(); k++) {
        if (!check_equal(zeroes[0].first, zeroes[0].second, zeroes[k].first, zeroes[k].second)) {
            can = false;
            break;
        }
    }
    for (int k = 1; k < ones.size(); k++) {
        if (!check_equal(ones[0].first, ones[0].second, ones[k].first, ones[k].second)) {
            can = false;
            break;
        }
    }
    if (len0 == len1) {
        if (check_equal(zeroes[0].first, zeroes[0].second, ones[0].first, ones[0].second)) {
            can = false;
        }
    }
    return can;
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int pt = rand() % 5712;
    cin >> s >> t;
    int n = t.size();
    for (int j = 0; j < 3; j++) {
        pw[j][0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[j][i] = mult(pw[j][i - 1], pt, mod[j]);
        }
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < t.size(); i++) {
            int val = t[i] - 'a';
            if (i == 0) hsh[j][i] = val;
            else hsh[j][i] = sum(hsh[j][i - 1], mult(val, pw[j][i], mod[j]), mod[j]);
        }
    }
    int zero = 0, one = 0;
    for (int i = 0; i < s.size(); i++) {
        zero += (s[i] == '0');
        one += (s[i] == '1');
    }
    int ans = 0;
    for (int len0 = 1; len0 <= n; len0++) {
        if (1LL * len0 * zero >= n) break;
        int left = n - len0 * zero;
        if (left % one != 0) continue;
        int len1 = left / one;
        if (go(len0, len1)) ans++;
    }
    cout << ans;
    return 0;
}