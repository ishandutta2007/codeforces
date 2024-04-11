#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            int x = 0, y = 0;
            for (int k = i; k < j; k++) {
                if (s[k] == 'U') y++;
                else if (s[k] == 'R') x++;
                else if (s[k] == 'D') y--;
                else x--;
            }
            
            if (x == 0 && y == 0) ans++;
        }

    cout << ans << '\n';
}