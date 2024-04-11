#include <bits/stdc++.h>

using namespace std;

bool check(vector< string > mat) {
    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            int ok;
            ok = 1;
            for(int iter = 0;iter < 3;iter++) {
                {
                    int x, y;
                    x = i;
                    y = j + iter;
                    if(x < 0 || x > 3 || y < 0 || y > 3) {
                        ok = 0;
                    }else {
                        if(mat[x][y] != 'x') {
                            ok = 0;
                        }
                    }
                }
            }
            if(ok) return 1;
            ok = 1;
            for(int iter = 0;iter < 3;iter++) {
                {
                    int x, y;
                    x = i + iter;
                    y = j;
                    if(x < 0 || x > 3 || y < 0 || y > 3) {
                        ok = 0;
                    }else {
                        if(mat[x][y] != 'x') {
                            ok = 0;
                        }
                    }
                }
            }
            if(ok) return 1;
            ok = 1;
            for(int iter = 0;iter < 3;iter++) {
                {
                    int x, y;
                    x = i + iter;
                    y = j + iter;
                    if(x < 0 || x > 3 || y < 0 || y > 3) {
                        ok = 0;
                    }else {
                        if(mat[x][y] != 'x') {
                            ok = 0;
                        }
                    }
                }
            }
            if(ok) return 1;
            ok = 1;
            for(int iter = 0;iter < 3;iter++) {
                {
                    int x, y;
                    x = i + iter;
                    y = j - iter;
                    if(x < 0 || x > 3 || y < 0 || y > 3) {
                        ok = 0;
                    }else {
                        if(mat[x][y] != 'x') {
                            ok = 0;
                        }
                    }
                }
            }
            if(ok) return 1;
        }
    }
    return 0;
}

int main() {

    vector< string > mat(4);

    for(int i = 0;i < 4;i++) {
        cin >> mat[i];
    }

    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            if(mat[i][j] != '.') continue;
            mat[i][j] = 'x';
            if(check(mat)) {
                cout << "YES\n";
                return 0;
            }
            mat[i][j] = '.';
        }
    }

    cout << "NO\n";

    return 0;
}