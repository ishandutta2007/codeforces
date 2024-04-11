#include <bits/stdc++.h>
using namespace std;
int t[20];
int cop[20];
int t1[20];
string a;
string b;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.size(); i++) {
        t[a[i] - '0']++;
    }
    for (int i = 0; i < b.size(); i++) {
        t1[b[i] - '0']++;
    }
    bool p = true;
    for (int i = 0; i <= 9; i++) {
        if (t[i] != t1[i]) p = false;
    }
    if (p) {
        cout << b;
        return 0;
    }
    if (a.size() < b.size()) {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < t[i]; j++) {
                cout << i;
            }
        }
        return 0;
    }
    long long mx = -1;
    for (int i = 0; i < b.size(); i++) {
        bool ok = true;
        long long ans = 0;
        for (int j = 0; j <= 9; j++) cop[j] = t[j];
        for (int k = 0; k < i; k++) {
            if (t[b[k] - '0'] == 0) ok = false;
            else {
                t[b[k] - '0']--;
                ans = ans * 10 + (b[k] - '0');
            }
        }
        int x = b[i] - '0';
        bool ok1 = false;
        for (int j = x - 1; j >= 0; j--) {
            if (ok1) break;
            if (t[j] > 0 && (j > 0 || i > 0)) {
                ok1 = true;
                t[j]--;
                ans = ans * 10 + j;
                break;
            }
        }
        for (int j = 9; j >= 0; j--) {
            for (int k = 0; k < t[j]; k++) {
                ans = ans * 10 + j;
            }
        }
        if (ok && ok1) mx = max(ans, mx);
        for (int j = 0; j <= 9; j++) t[j] = cop[j];
    }
    cout << mx;
    return 0;
}