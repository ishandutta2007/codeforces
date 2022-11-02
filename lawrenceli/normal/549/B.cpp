#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, a[MAXN], b[MAXN];
bool mat[MAXN][MAXN];

void go() {
    for (int i=0; i<n; i++)
        if (a[i] == 0 && !b[i]) {
            b[i] = 1;
            for (int j=0; j<n; j++)
                if (mat[i][j]) a[j]--;
            go();
            break;
        }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            char c;
            cin >> c;
            mat[i][j] = c == '1' ? 1 : 0;
        }

    for (int i=0; i<n; i++) cin >> a[i];

    go();

    int cnt = 0;
    for (int i=0; i<n; i++) cnt += b[i];
    cout << cnt << '\n';
    for (int i=0; i<n; i++)
        if (b[i]) cout << i+1 << ' ';
}