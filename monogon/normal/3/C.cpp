
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s[3];

bool row3(char c) {
    for(int i = 0; i < 3; i++) {
        if(s[i][0] == c && s[i][1] == c && s[i][2] == c) return true;
        if(s[0][i] == c && s[1][i] == c && s[2][i] == c) return true;
    }
    if(s[0][0] == c && s[1][1] == c && s[2][2] == c) return true;
    if(s[0][2] == c && s[1][1] == c && s[2][0] == c) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x = 0, o = 0;
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(s[i][j] == 'X') x++;
            else if(s[i][j] == '0') o++;
        }
    }
    if(x - o < 0 || x - o > 1) {
        cout << "illegal" << endl;
        return 0;
    }
    bool x3 = row3('X'), o3 = row3('0');
    if((x3 && o3) || (x3 && x == o) || (o3 && x > o)) {
        cout << "illegal" << endl;
    }else if(x3) {
        cout << "the first player won" << endl;
    }else if(o3) {
        cout << "the second player won" << endl;
    }else if(o + x == 9) {
        cout << "draw" << endl;
    }else if(x == o) {
        cout << "first" << endl;
    }else {
        cout << "second" << endl;
    }
}