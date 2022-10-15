/**
 * @author Macesuted (macesuted@outlook.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define maxn 55

typedef pair<int, int> pii;

char a[maxn][maxn];

void work(void) {
    int n;
    string str;
    cin >> n >> str;
    str = ' ' + str;
    vector<int> que;
    for (register int i = 1; i <= n; i++)
        if (str[i] == '2') que.push_back(i);
    if (que.size() == 1 || que.size() == 2) return cout << "NO" << endl, void();
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= n; j++)
            a[i][j] = '=';
    for (vector<int>::iterator i = que.begin(); i != que.end(); i++) {
        vector<int>::iterator j = i + 1;
        if (j == que.end()) j = que.begin();
        a[*i][*j] = '+', a[*j][*i] = '-';
    }
    cout << "YES" << endl;
    for (register int i = 1; i <= n; i++) {
        for (register int j = 1; j <= n; j++)
            if (i == j)
                cout << 'X';
            else
                cout << a[i][j];
        cout << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    int _ = 1;
    cout << setprecision(11);
    cin >> _;
    while (_--) work();
    return 0;
}