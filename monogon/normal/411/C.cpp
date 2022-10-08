
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int a[4][2];

// wtf

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 4; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    if((a[0][0] > a[2][1] && a[1][1] > a[3][0] && a[0][0] > a[3][1] && a[1][1] > a[2][0]) ||
       (a[1][0] > a[2][1] && a[0][1] > a[3][0] && a[1][0] > a[3][1] && a[0][1] > a[2][0])) {
        cout << "Team 1\n";
    }else if(((a[2][0] > a[0][1] && a[3][1] > a[1][0]) || (a[3][0] > a[0][1] && a[2][1] > a[1][0])) &&
             ((a[2][0] > a[1][1] && a[3][1] > a[0][0]) || (a[3][0] > a[1][1] && a[2][1] > a[0][0]))) {
        cout << "Team 2\n";
    }else {
        cout << "Draw\n";
    }
}