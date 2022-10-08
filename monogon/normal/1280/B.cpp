
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 0: all cells are A
// 1: an entire extreme row or column is A
// 2: a corner is A, or an entire row or column is A
// 3: an edge is A
// 4: there is an A
// MORTAL: there is no A

const int N = 65;
int t, r, c;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> r >> c;
        int i, j;
        for(int i = 0; i < r; i++) {
            cin >> s[i];
        }
        case0:
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                if(s[i][j] == 'P') goto case1;
            }
        }
        cout << 0 << endl;
        continue;

        case1:
        for(i = 0; i < r; i++) {
            if(s[i][0] == 'P') break;
        }
        if(i == r) goto case12;
        for(i = 0; i < r; i++) {
            if(s[i][c - 1] == 'P') break;
        }
        if(i == r) goto case12;
        for(j = 0; j < c; j++) {
            if(s[0][j] == 'P') break;
        }
        if(j == c) goto case12;
        for(j = 0; j < c; j++) {
            if(s[r - 1][j] == 'P') break;
        }
        if(j < c) goto case2;

        case12:
        cout << 1 << endl;
        continue;

        case2:
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                if(s[i][j] == 'P') break;
            }
            if(j == c) goto out2;
        }
        for(j = 0; j < c; j++) {
            for(i = 0; i < r; i++) {
                if(s[i][j] == 'P') break;
            }
            if(i == r) goto out2;
        }

        case22:
        if(s[0][0] == 'P' && s[0][c - 1] == 'P' && s[r - 1][0] == 'P' && s[r - 1][c - 1] == 'P') goto case3;

        out2:
        cout << 2 << endl;
        continue;

        case3:
        for(i = 0; i < r; i++) {
            if(s[i][0] == 'A' || s[i][c - 1] == 'A') break;
        }
        for(j = 0; j < c; j++) {
            if(s[0][j] == 'A' || s[r - 1][j] == 'A') break;
        }
        if(i == r && j == c) goto case4;
        cout << 3 << endl;
        continue;

        case4:
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                if(s[i][j] == 'A') break;
            }
            if(j < c) break;
        }
        if(i == r) goto mortal;
        cout << 4 << endl;
        continue;

        mortal:
        cout << "MORTAL" << endl;
    }
}