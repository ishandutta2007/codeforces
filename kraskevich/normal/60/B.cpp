#include <iostream>
#include <string>
using namespace std;

int n, m, k;
string s[10][10];
int cnt = 0;

int dx[6] = {-1, 0, 0, 0, 0, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 1, 0, 0, -1, 0}; 

void dfs(int x, int y, int z) {
     s[z][x][y] = '#';
     ++cnt;
     for(int i = 0; i < 6; ++i) {
             int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
             if(nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < k && s[nz][nx][ny] == '.')
                   dfs(nx, ny, nz);
     }
}

int main() {
    cin >> k >> n >> m;
    for(int i = 0; i < k; ++i) 
            for(int j = 0; j < n; ++j)
                    cin >> s[i][j];
    int x, y,  z = 0;
    cin >> x >> y;
    --x, --y;
    dfs(x, y, z);
    cout << cnt;
    cin >> n;
    return 0;
}