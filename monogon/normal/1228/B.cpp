
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005, M = 1000000007;
int h, w;
int r[N], c[N];
// 0 = unknown, 1 = full, 2 = empty
int arr[N][N];

bool setcell(int i, int j, int x) {
    if(arr[i][j] == 0 || arr[i][j] == x) {
        arr[i][j] = x;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        cin >> r[i];
        for(int j = 0; j < r[i]; j++) {
            if(!setcell(i, j, 1)) {
                cout << 0 << endl;
                return 0;
            }
        }
        if(r[i] < w && !setcell(i, r[i], 2)) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int j = 0; j < w; j++) {
        cin >> c[j];
        for(int i = 0; i < c[j]; i++) {
            if(!setcell(i, j, 1)) {
                cout << 0 << endl;
                return 0;
            }
        }
        if(c[j] < h && !setcell(c[j], j, 2)) {
            cout << 0 << endl;
            return 0;
        }
    }
    // count 0's, 2 to the power
    long ans = 1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(arr[i][j] == 0) {
                ans = (ans * 2) % M;
            }
        }
    }
    cout << ans << endl;
}