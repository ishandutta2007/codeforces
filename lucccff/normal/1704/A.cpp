#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> s;
        for(int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        cin >> s;
        for(int i = n - m; i < n; i++) {
            b[i] = s[i - n + m] - '0';
        }
        int flag = 1;
        for(int i = n - m + 1; i < n; i++) {
            if (a[i] != b[i]) flag = 0;
        }
        if (!flag) {
            cout << "NO\n";
            continue;
        }
        flag = 0;
        for(int i = 0; i <= n - m; i++) {
            if (a[i] == b[n - m]) flag = 1;
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}