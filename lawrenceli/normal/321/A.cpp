#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int a, b;
string s;
int sx, sy, x, y, n;

int sign(int i) {
    if (i==0) return 0;
    if (i<0) return -1;
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> a >> b >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='U') sy++;
        else if (s[i]=='D') sy--;
        else if (s[i]=='L') sx--;
        else sx++;
    }
    if (sign(sx)!=sign(a) && sign(sx)!=0) {
        for (int j=0; j<500; j++) {
            for (int i=0; i<s.length(); i++) {
                if (x==a && y==b) {
                    cout << "Yes" << endl;
                    return 0;
                }
                if (s[i]=='U') y++;
                else if (s[i]=='D') y--;
                else if (s[i]=='L') x--;
                else x++;
            }
        }
        if (x==a && y==b) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    else {
        int n;
        if (sx==0) {
            if (sy==0) n=0;
            else n=max(0, b/sy-200);
        }
        else {
            n=max(0, a/sx-200);
        }
        x+=sx*n;
        y+=sy*n;
        for (int j=0; j<500; j++) {
            for (int i=0; i<s.length(); i++) {
                if (x==a && y==b) {
                    cout << "Yes" << endl;
                    return 0;
                }
                if (s[i]=='U') y++;
                else if (s[i]=='D') y--;
                else if (s[i]=='L') x--;
                else x++;
            }
        }
        if (x==a && y==b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}