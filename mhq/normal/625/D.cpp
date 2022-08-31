#include <bits/stdc++.h>
using namespace std;
int rev(int a) {
    while (a % 10 == 0) a /= 10;
    int s = 0;
    while (a > 0) {
        s = 10 * s + (a % 10);
        a /= 10;
    }
    return s;
}
string q;
int s[(int)1e5 + 10];
int s1[(int)1e5 + 10];
int s2[(int)1e5 + 10];
int ans[(int)1e5 + 10];
bool solve1(int l, int r, int tp) {
    if (l > r) return true;
    if (s[l] < 0 || s[r] < 0) return false;
    if (tp == 0) {
        if (s[l] == s[r]) {
            s1[l] = s[l];
            s1[r] = s[r];
            return solve1(l + 1, r - 1, 0);
        }
        if (s[l] == s[r] + 1) {
            s1[l] = s[r];
            s1[r] = s[r];
            if (l + 1 == r) return false;
            return solve1(l + 1, r - 1, 1);
        }
        return false;
    }
    if (tp == 1) {
        if (s[l] == s[r]) {
            s1[l] = s[l] + 10;
            s1[r] = s[r] + 10;
            bool ok = false;
            for (int i = r - 1; i >= l + 1; i--) {
                if (s[i] > 0) {
                    ok = true;
                    s[i]--;
                    break;
                }
                s[i] = 9;
            }
            if (l == r) return true;
            if (!ok) return false;
            if (l + 1 == r) return false;
            return solve1(l + 1, r - 1, 0);
        }
        if (s[l] == s[r] + 1) {
            s1[l] = s[l] + 10;
            s1[r] = s[r] + 10;
            bool ok = false;
            for (int i = r - 1; i >= l; i--) {
                if (s[i] > 0) {
                    ok = true;
                    s[i]--;
                    break;
                }
                s[i] = 9;
            }
            if (s[l] == s[r]) return solve1(l + 1, r - 1, 0);
            if (!ok && (l + 1) != r) return false;
            return solve1(l + 1, r - 1, 1);
        }
        if (s[l] == 0 && s[r] == 9) {
            s1[l] = 9;
            s1[r] = 9;
            if (l + 1 == r) return false;
            return solve1(l + 1, r - 1, 1);
        }
        return false;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    /*int n = 1000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (j + rev(j) == i) {
                cout << j << " + " << rev(j) << " = " << i << '\n';
                break;
             }
        }
    }
    return 0;*/
    cin >> q;
    if (q.size() == 1 && q[0] == '1') {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < q.size(); i++) {
        s[i] = q[i] - '0';
    }
    if (s[0] == 1) {
        if (solve1(1, q.size() - 1, 1)) {
            bool ok = true;
            for (int i = 1; 2 * i <= q.size(); i++) {
                if (s1[i] < 0) ok = false;
                ans[i] = min(9, s1[i]);
                if (2 * i == q.size()) {
                    if (s1[i] % 2 != 0) ok = false;
                    else ans[i] = s1[i] / 2;
                }
            }
            for (int i = q.size() - 1; 2 * i > q.size(); i--) {
                ans[i] = s1[i] - ans[q.size() - i];
            }
            if (ans[1] == 0) ok = false;
            if (ok) {
                for (int i = 1; i <= q.size() - 1; i++) {
                    cout << ans[i];
                }
                return 0;
            }
        }
    }
    for (int i = 0; i < q.size(); i++) {
        s[i] = q[i] - '0';
    }
    if (solve1(0, q.size() - 1, 0)) {
        //cout << s1[0] << " " << s1[1] << " " << s1[2] << '\n';
        bool ok = true;
        for (int i = 0; 2 * i <= q.size() - 1; i++) {
            if (s1[i] < 0) ok = false;
            ans[i] = min(9, s1[i]);
            if (2 * i == q.size() - 1) {
                if (s1[i] % 2 != 0) ok = false;
                else ans[i] = s1[i] / 2;
            }
        }
        for (int i = q.size() - 1; 2 * i > q.size() - 1; i--) {
            ans[i] = s1[i] - ans[q.size() - 1 - i];
            if (ans[i] >= 10) ok = false;
        }
        if (ans[0] == 0) ok = false;
        if (ok) {
            for (int i = 0; i <= q.size() - 1; i++) {
                cout << ans[i];
            }
            return 0;
        }
    }
    cout << 0;
    return 0;
}