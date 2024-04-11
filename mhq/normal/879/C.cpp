#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 5 * (int)1e5 + 5;
vector < int  > g[N];
vector  < int > bin (int x) {
    vector < int > a;
    for (int i = 0; i < 10; i++) {
        a.push_back(x % 2);
        x = x / 2;
    }
    return a;
}
char s[N];
int a[N];
int ans[10][2];
vector < int > x1;
vector < int > x2;
vector < int > x3;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cin >> a[i];
        g[i] = bin(a[i]);
    }
    /*if (n < 5) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << s[i] << " " << a[i] << '\n';
        }
        return 0;
    }*/
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            int t = j;
            for (int k = 0; k < n; k++){
                if (s[k] == '&') {
                    t &= g[k][i];
                }
                else if (s[k] == '^') {
                    t ^= g[k][i];
                }
                else t |= g[k][i];
            }
            ans[i][j] = t;
        }
    }
    cout << 3 << '\n';
    for (int i = 0; i < 10; i++) {
        if (ans[i][0] == 0 && ans[i][1] == 0) {
            x1.push_back(1);
            x2.push_back(1);
            x3.push_back(1);
        }
        if (ans[i][0] == 0 && ans[i][1] == 1) {
            x1.push_back(0);
            x2.push_back(1);
            x3.push_back(0);
        }
        if (ans[i][0] == 1 && ans[i][1] == 0) {
            x1.push_back(0);
            x2.push_back(1);
            x3.push_back(1);
        }
        if (ans[i][0] == 1 && ans[i][1] == 1) {
            x1.push_back(1);
            x2.push_back(1);
            x3.push_back(0);
        }
    }
    int cur1 = 0; int cur2 = 0; int cur3 = 0;
    reverse(x1.begin(), x1.end());
    reverse(x2.begin(), x2.end());
    reverse(x3.begin(), x3.end());
    for (int i = 0; i < 10; i++) {
        cur1 = cur1 * 2 + x1[i];
        cur2 = cur2 * 2 + x2[i];
        cur3 = cur3 * 2 + x3[i];
    }
    cout << '|' << " " << cur1 << '\n';
    cout << '&' << " " << cur2 << '\n';
    cout << '^' << " " << cur3 << '\n';
    return 0;
}