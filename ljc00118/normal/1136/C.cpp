#include <bits/stdc++.h>
using namespace std;

const int N = 505;

map <int, int> t[N << 1];
int a[N][N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            ++t[i + j][a[i][j]];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp; cin >> tmp;
            if(t[i + j][tmp] == 0) {
                cout << "NO" << endl;
                return 0;
            }
            --t[i + j][tmp];
        }
    }
    cout << "YES" << endl;
    return 0;
}