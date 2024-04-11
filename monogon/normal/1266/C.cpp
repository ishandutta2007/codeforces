
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 505;
int r, c;
ll a[N][N];
ll b[N][N];

// 2 3 4
// number rows 1, ..., r
// number cols r+1, ..., r + c

// r < c
void solve() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            a[i][j] = lcm(i + 1, r + j + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c;
    if(r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }
    if(r > c) {
        swap(r, c);
        solve();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                b[j][i] = a[i][j];
            }
        }
        swap(r, c);
    }else {
        solve();
        swap(b, a);
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}