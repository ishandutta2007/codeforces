#include <bits/stdc++.h>
using namespace std;
int k, n;
string s[2505];
string cop[2505];
bool used[26];
bool ok = false;
bool checkk(int a, int b) {
    int cnt = 0;
    int pt1 = 0;
    int pt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[a][i] != s[b][i]) {
            if (cnt == 0) pt1 = i;
            else if (cnt == 1) pt2 = i;
            else return false;
            cnt++;
        }
    }
    if (cnt == 0 && ok == false) return false;
    if (cnt == 1) return false;
    if (s[a][pt1] != s[b][pt2] || s[a][pt2] != s[b][pt1]) return false;
    return true;
}
void check(int ind) {
    for (int i = 1; i <= k; i++) {
        if (i == ind) continue;
        if (!checkk(i, ind)) {
            return ;
        }
    }
    cout << s[ind];
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        cop[i] = s[i];
    }
    for (int i = 0; i < n; i++) {
        if (used[s[1][i] - 'a']) ok = true;
        used[s[1][i] - 'a'] = true;
    }
    int pos = -1;
    int ind1 = -1;
    int ind2 = -1;
    for (int i = 0; i < n; i++) {
        if (pos != -1) break;
        char c = s[1][i];
        int ind = i;
        for (int j = 1; j <= k; j++) {
            if (s[j][i] != c) {
                pos = i;
                ind1 = 1;
                ind2 = j;
                break;
            }
        }
    }
    if (pos == -1) {
        swap(s[1][0], s[1][1]);
        cout << s[1];
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            continue;
        }
        swap(s[ind1][i], s[ind1][pos]);
        check(ind1);
        swap(s[ind1][i], s[ind1][pos]);
    }
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            continue;
        }
        swap(s[ind2][i], s[ind2][pos]);
        check(ind2);
        swap(s[ind2][i], s[ind2][pos]);
    }
    cout << -1;
    return 0;
}