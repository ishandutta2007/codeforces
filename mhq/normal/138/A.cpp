#include <bits/stdc++.h>
using namespace std;
const int maxN = 2505;
int n, k;
string s[4 * maxN];
int type[4 * maxN];
bool vowel(char x) {
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}
string get(int x) {
    int cnt = 0;
    int ind = -1;
    for (int i = s[x].size() - 1; i >= 0; i--) {
        if (vowel(s[x][i])) cnt++;
        if (cnt == k) {
            ind = i;
            break;
        }
    }
    string t = "";
    if (cnt != k) return t;
    return s[x].substr(ind);
}
bool ok(int x, int y) {
    return ((get(x) != "") && get(x) == get(y));
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < 4 * n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        int ind[4] = {4 * i, 4 * i + 1, 4 * i + 2, 4 * i + 3};
        if (ok(ind[0], ind[1]) && ok(ind[0], ind[2]) && ok(ind[0], ind[3])) type[i] = 3;
        else if (ok(ind[0], ind[1]) && ok(ind[2], ind[3])) type[i] = 0;
        else if (ok(ind[0], ind[2]) && ok(ind[1], ind[3])) type[i] = 1;
        else if (ok(ind[0], ind[3]) && ok(ind[1], ind[2])) type[i] = 2;
        else type[i] = -1;
    }
    int cur = type[0];
    for (int i = 0; i < n; i++) {
        if (type[i] == 3) continue;
        if (cur == 3) cur = type[i];
        if (cur != type[i]) cur = -1;
    }
    if (cur == -1) cout << "NO";
    else if (cur == 0) cout << "aabb";
    else if (cur == 1) cout << "abab";
    else if (cur == 2) cout << "abba";
    else cout << "aaaa";
    return 0;
}