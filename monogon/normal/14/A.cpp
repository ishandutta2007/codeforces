
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 55;
int n, m;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int mx = N, my = N, Mx = -1, My = -1;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '*') {
                mx = min(mx, i);
                my = min(my, j);
                Mx = max(Mx, i);
                My = max(My, j);
            }
        }
    }
    for(int i = mx; i <= Mx; i++) {
        for(int j = my; j <= My; j++) {
            cout << s[i][j];
        }
        cout << "\n";
    }
}