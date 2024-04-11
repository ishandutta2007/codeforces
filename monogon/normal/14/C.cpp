
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll _x1[4], _y1[4], _x2[4], _y2[4];
ll X1[4], Y1[4], X2[4], Y2[4];

bool check() {
    return Y1[0] == Y2[0] && Y1[1] == Y2[1] && X1[0] < X2[0] && X1[1] < X2[1] &&
            X1[2] == X2[2] && X1[3] == X2[3] && Y1[2] < Y2[2] && Y1[3] < Y2[3] &&
            X1[0] == X1[2] && Y1[0] == Y1[2] &&
            X2[0] == X1[3] && Y2[0] == Y1[3] &&
            X1[1] == X2[2] && Y1[1] == Y2[2] &&
            X2[1] == X2[3] && Y2[1] == Y2[3];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 4; i++) {
        cin >> _x1[i] >> _y1[i] >> _x2[i] >> _y2[i];
    }
    vector<int> v = {0, 1, 2, 3};
    do {
        for(int mask = 0; mask < 16; mask++) {
            for(int i = 0; i < 4; i++) {
                X1[i] = _x1[v[i]];
                Y1[i] = _y1[v[i]];
                X2[i] = _x2[v[i]];
                Y2[i] = _y2[v[i]];
                if((mask >> i) & 1) {
                    swap(X1[i], X2[i]);
                    swap(Y1[i], Y2[i]);
                }
            }
            if(check()) {
                cout << "YES\n";
                return 0;
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << "NO\n";
}