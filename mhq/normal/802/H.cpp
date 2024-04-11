#include <bits/stdc++.h>
using namespace std;
int n;
int c[50][50];
string s;
int ans[50];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //cout << char('a' + 0);
    cin >> n;
    int k = 10;
    c[0][0] = 1;
    for (int i = 1; i <= 40; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int i = 10; i >= 1; i--) {
        int cur = 0;
        for (cur = 0; ; cur++) {
            if (c[i + k - 1][k] * (cur + 1) > n) break;
        }
        ans[i] = cur;
        n -= cur * c[i + k - 1][k];
    }
    int sz = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < k; j++) {
            cout << char('a' + j);
        }
        sz += ans[i];
        sz += k;
        for (int j = 0; j < ans[i]; j++) cout << char('a' + k);
    }
    cout << " ";
    for (int i = 0; i <= k; i++) cout << char('a' + i);
    return 0;
}