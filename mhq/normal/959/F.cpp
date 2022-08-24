#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int maxN = (int)1e5 + 10;
int pw[maxN];
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n, q;
vector < int > p[maxN];
int a[maxN];
bool used[maxN];
bool ok(vector < int > &s, int x) {
    //if (x == 0) cout << "HRER" << endl;
    if (s.size() == 0) return (x == 0);
    int l = 0;
    for (int i = 19; i >= 0; i--) {
        if ((x & (1 << i)) == 0) continue;
        int t = -1;
        for ( ; l < s.size(); l++) {
            if (s[l] & (1 << i)) {
                t = l;
                x ^= s[l];
                break;
            }
        }
        if (t == -1) return false;
    }
    return (x == 0);
}
void reduce(vector < int > &s) {
    //if (s.size() == 2) cout << s[0] << " " << s[1] << endl;
    memset(used, 0, sizeof used);
    for (int i = 19; i >= 0; i--) {
        int t = -1;
        for (int j = 0; j < s.size(); j++) {
            if (used[j]) continue;
            if (s[j] & (1 << i)) {
                t = j;
            }
        }
        if (t == -1) continue;
        used[t] = true;
        for (int j = 0; j < s.size(); j++) {
            if (j == t) continue;
            if (s[j] & (1 << i)) s[j] ^= s[t];
        }
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
}
// a_1, a_2, a_3, a_4, a_5..a_n;
// a1, a2, .. an
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("cruel.in", "r", stdin);
    //freopen("cruel.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    pw[0] = 1;
    for (int i = 1; i < maxN; i++) pw[i] = sum(pw[i - 1], pw[i - 1]);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (ok(p[i - 1], a[i])) p[i] = p[i - 1];
        else {
            p[i] = p[i - 1];
            p[i].push_back(a[i]);
            reduce(p[i]);
        }
    }
    /*for (int i = 1; i <= n; i++) {
        cout << p[i].size() << '\n';
        for (int j = 0; j < p[i].size(); j++) cout << p[i][j] << " ";
        cout << "/////" << endl;
    }*/
    for (int i = 1; i <= q; i++) {
        int l, x;
        cin >> l >> x;
        if (ok(p[l], x)) cout << pw[l - p[l].size()] << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}