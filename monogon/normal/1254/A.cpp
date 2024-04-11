
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int q, r, c, k;
string s[N];
int ans[N][N];

char getchar(int x) {
    if(x <= 9) return '0' + x;
    if(x >= 10 && x < 36) return 'a' + x - 10;
    return 'A' + x - 10 - 26;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> r >> c >> k;
        int R = 0;
        for(int i = 0; i < r; i++) {
            cin >> s[i];
            for(int j = 0; j < c; j++) {
                R += (s[i][j] == 'R');
            }
        }
        int a = R - k * (R / k);
        int rice = 0;
        int chicken = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int l = (i % 2 ? j : c - j - 1);
                rice += (s[i][l] == 'R');
                ans[i][l] = chicken;
                if((chicken >= a && rice == R / k) || rice == (R + k - 1) / k) {
                    chicken++;
                    if(chicken == k) chicken = k - 1;
                    rice = 0;
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << getchar(ans[i][j]);
            }
            cout << endl;
        }
    }
}