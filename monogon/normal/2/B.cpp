
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n;
int a[N][N];
int a2[N][N], a5[N][N];
int dp2[N][N], dp5[N][N];
char dir2[N][N], dir5[N][N];
int zi, zj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    zi = -1, zj = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                a2[i][j] = a5[i][j] = 2;
                zi = i;
                zj = j;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            while(a[i][j] != 0 && a[i][j] % 2 == 0) {
                a[i][j] /= 2;
                a2[i][j]++;
            }
            while(a[i][j] != 0 && a[i][j] % 5 == 0) {
                a[i][j] /= 5;
                a5[i][j]++;
            }
            if(i == 0 && j == 0) {
                dp2[i][j] = a2[i][j];
                dp5[i][j] = a5[i][j];
            }else if(i == 0) {
                dp2[i][j] = a2[i][j] + dp2[i][j - 1];
                dp5[i][j] = a5[i][j] + dp5[i][j - 1];
                dir2[i][j] = dir5[i][j] = 'R';
            }else if(j == 0) {
                dp2[i][j] = a2[i][j] + dp2[i - 1][j];
                dp5[i][j] = a5[i][j] + dp5[i - 1][j];
                dir2[i][j] = dir5[i][j] = 'D';
            }else {
                if(dp2[i - 1][j] < dp2[i][j - 1]) {
                    dp2[i][j] = a2[i][j] + dp2[i - 1][j];
                    dir2[i][j] = 'D';
                }else {
                    dp2[i][j] = a2[i][j] + dp2[i][j - 1];
                    dir2[i][j] = 'R';
                }
                if(dp5[i - 1][j] < dp5[i][j - 1]) {
                    dp5[i][j] = a5[i][j] + dp5[i - 1][j];
                    dir5[i][j] = 'D';
                }else {
                    dp5[i][j] = a5[i][j] + dp5[i][j - 1];
                    dir5[i][j] = 'R';
                }
            }
        }
    }
    int m = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);
    if(zi != -1 && m > 0) {
        cout << 1 << endl;
        for(int i = 0; i < zi; i++) {
            cout << 'D';
        }
        for(int j = 0; j < n - 1; j++) {
            cout << 'R';
        }
        for(int i = zi; i < n - 1; i++) {
            cout << 'D';
        }
        cout << endl;
    }else {
        cout << m << endl;
        string s = "";
        int i = n - 1, j = n - 1;
        if(dp5[n - 1][n - 1] == m) swap(dir2, dir5);
        while(i > 0 || j > 0) {
            s.push_back(dir2[i][j]);
            if(dir2[i][j] == 'D') i--;
            else j--;
        }
        string s2(s.rbegin(), s.rend());
        cout << s2 << endl;
    }
}