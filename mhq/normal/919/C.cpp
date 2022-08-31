#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char a[2005][2005];
int ans;
int cnt;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') cnt++;
        }
    }
    if (k == 1) {
        cout << cnt;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        vector < int > emp;
        emp.push_back(0);
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*') emp.push_back(j);
        }
        emp.push_back(m + 1);
        for (int j = 0; j + 1 < emp.size(); j++) {
            ans += max(emp[j + 1] - emp[j] - k, 0);
        }
    }
    for (int j = 1; j <= m; j++) {
        vector < int > emp;
        emp.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == '*') emp.push_back(i);
        }
        emp.push_back(n + 1);
        for (int i = 0; i + 1 < emp.size(); i++) {
            ans += max(emp[i + 1] - emp[i] - k, 0);
        }
    }
    cout << ans;
    return 0;
}