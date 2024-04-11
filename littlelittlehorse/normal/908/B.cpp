#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int N(55);

char a[N][N];
int o[4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy, tx, ty;
    for(int i(0); i < n; i++) {
        cin >> a[i];
        for(int j(0); j < m; j++) {
            if(a[i][j] == 'S') {
                sx = i; sy = j;
                a[i][j] = '.';
            }else if(a[i][j] == 'E') {
                tx = i; ty = j;
                a[i][j] = '.';
            }
        }
    }
    string st;
    cin >> st;
    int ans = 0;
    for(int i(0); i < 4; i++) o[i] = i;
    do {
        int x(sx), y(sy);
        bool flag(true);
        for(char c : st) {
            int d(o[(c - '0')]);
            int X(x + dx[d]), Y(y + dy[d]);
            if(X < 0 || X >= n || Y < 0 || Y >= m || a[X][Y] == '#') {
                flag = false;
                break;
            }
            x = X; y = Y;
            if(x == tx && y == ty) 
                break;
        }
        if(x != tx || y != ty || !flag) {
        }else {
            ans++;
        }
    } while(next_permutation(o, o + 4));
    cout << ans << endl;
}