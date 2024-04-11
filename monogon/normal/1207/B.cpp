
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 55;
int n, m;
int a[MAX_N][MAX_N];
set<pair<int, int> > ops;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) continue;
            for(int x = max(0, i - 1); x <= i; x++) {
                for(int y = max(0, j - 1); y <= j; y++) {
                    if(a[x][y] && a[x + 1][y] && a[x][y + 1] && a[x + 1][y + 1]) {
                        ops.insert({x + 1, y + 1});
                        goto endloop;
                    }
                }
            }
            cout << -1 << endl;
            return 0;
            endloop:;
        }
    }
    cout << ops.size() << endl;
    for(auto p : ops) {
        cout << p.first << " " << p.second << endl;
    }
}