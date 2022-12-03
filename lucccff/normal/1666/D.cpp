#include <bits/stdc++.h>
using namespace std;

int a[30], b[30];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int k = s1.length() - 1, flag = 1;
        for(int i = s2.length() - 1; i >= 0; i--) {
            while (k >= 0 && s1[k] != s2[i]) {
                b[s1[k] - 'A']++;
                k--;
            }
            if (k < 0 || b[s1[k] - 'A'] != 0) {
                flag = 0;
                break;
            }
            k--;
        }
        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}