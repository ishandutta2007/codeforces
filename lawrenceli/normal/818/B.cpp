#include <bits/stdc++.h>

using namespace std;

int n, m;
int l[105];
int a[105];

int blah(int x, int y) {
    return x == y ? n : (y + n - x) % n;
}

int main() {
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        if (i > 0) {
            int x = blah(l[i - 1], l[i]);
            if (a[l[i - 1]] == -1) a[l[i - 1]] = x;
            else if (a[l[i - 1]] != x) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int ind = -1;
        int num = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] == -1) ind = j;
            else if (a[j] == i) num++;
        }
        if (num == 0) a[ind] = i;
        else if (num > 1) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}