
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 205;
int n, m, k, sx[N], sy[N], fx[N], fy[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> sx[i] >> sy[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> fx[i] >> fy[i];
    }
    string s;
    for(int i = 0; i < m - 1; i++) {
        s.push_back('L');
    }
    for(int i = 0; i < n - 1; i++) {
        s.push_back('U');
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(i % 2 == 0) {
                s.push_back('D');
            }else {
                s.push_back('U');
            }
        }
        s.push_back('R');
    }
    cout << s.length() << "\n" << s << "\n";
}