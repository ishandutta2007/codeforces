
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ve[2];
    #define BLACK 0
    #define WHITE 1
    
    // color the cells like a checkerboard
    // ve[COLOR] = {list of unfilled cells of that color}
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ve[(i + j) % 2].push_back({i, j});
        }
    }

    for(int t = 1; t <= n * n; t++) {
        int a, b, i, j, col;
        cin >> a;

        // choose an available checkerboard color and a token color for it
        if(a == 1) {
            if(!ve[BLACK].empty()) {
                col = BLACK;
                b = 2;
            }else {
                col = WHITE;
                b = 3;
            }
        }else if(a == 2) {
            if(!ve[WHITE].empty()) {
                col = WHITE;
                b = 1;
            }else {
                col = BLACK;
                b = 3;
            }
        }else { // a == 3
            if(!ve[WHITE].empty()) {
                col = WHITE;
                b = 1;
            }else {
                col = BLACK;
                b = 2;
            }
        }
        tie(i, j) = ve[col].back();
        ve[col].pop_back();
        cout << b << ' ' << i << ' ' << j << endl;
    }
}