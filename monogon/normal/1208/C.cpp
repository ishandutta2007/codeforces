
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n;
int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i += 4) {
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < 4; j++) {
                a[i + j][k] = cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}