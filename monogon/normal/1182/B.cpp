
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_H = 505;
int w, h;
string str[MAX_H];

int main() {
    cin >> h >> w;
    int sum = 0;
    int row = -1;
    int col = -1;
    for(int i = 0; i < h; i++) {
        cin >> str[i];
        for(int j = 0; j < w; j++) {
            if(str[i][j] == '*') {
                sum++;
                if(j > 0 && str[i][j - 1] == '*') {
                    row = i;
                }
                if(i > 0 && str[i - 1][j] == '*') {
                    col = j;
                }
            }
        }
    }
    if(row <= 0 || row >= h - 1 || col <= 0 || col >= w - 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<pair<int, int>> v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(pair<int, int> d : v) {
        int dx = d.first;
        int dy = d.second;
        int i = row;
        int j = col;
        i += dx;
        j += dy;
        int times = 0;
        while(i >= 0 && j >= 0 && i < h && j < w) {
            if(str[i][j] == '*') {
                times++;
            }else break;
            i += dx;
            j += dy;
        }
        sum -= times;
        if(times == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << (sum == 1 ? "YES" : "NO") << endl;
}