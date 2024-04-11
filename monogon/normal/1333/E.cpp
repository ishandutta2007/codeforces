
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 505;
int n;
int grid[N][N];

int special[3][3] =
{
    {1, 5, 3},
    {9, 2, 8},
    {4, 6, 7}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n <= 2) {
        cout << "-1\n";
        return 0;
    }
    int cnt = 1;
    int r = 1, c = 1;
    for(int j = 1; j <= n - 3; j++) {
        if(j % 2 == 0) {
            for(int i = 1; i <= n; i++) {
                grid[i][j] = cnt++;
                r = i;
                c = j;
            }
        }else {
            for(int i = n; i > 0; i--) {
                grid[i][j] = cnt++;
                r = i;
                c = j;
            }
        }
    }
    c++;
    while(cnt <= n * n - 9) {
        grid[r][c] = cnt++;
        if(c < n && grid[r][c + 1] == 0) c++;
        else if(c > 1 && grid[r][c - 1] == 0) c--;
        else if(r > 1 && grid[r - 1][c] == 0) r--;
        else r++;
    }
    int sr = 0, sc = 0;
    bool flag = true;
    for(int i = 1; i <= n && flag; i++) {
        for(int j = 1; j <= n && flag; j++) {
            if(grid[i][j] == 0) {
                sr = i;
                sc = j;
                flag = false;
            }
        }
    }
    bool b1 = (sr == r);
    bool b2 = (sc == c);
    for(int i = 0; i < 3; i++) {
        int rr = sr + (b1 ? i : 2 - i);
        for(int j = 0; j < 3; j++) {
            int cc = sc + (b2 ? j : 2 - j);
            grid[rr][cc] = cnt - 1 + special[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}