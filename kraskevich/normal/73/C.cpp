#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    string s;
    cin >> s;
    int k;
    cin >> k;
    int c[26][26];
    for(int i = 0; i < 26; ++i)
              for(int j = 0; j < 26; ++j)
                      c[i][j] = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
            char a, b;
            cin >> a >> b;
            cin >> c[a - 'a'][b - 'a'];
    } 
    
    n = s.length();
    int f[n][1000][26];
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < 1000; ++j)
                    for(int l = 0; l < 26; ++l)
                            f[i][j][l] = -1000 * 1000 * 1000;
    f[0][0][s[0] - 'a'] = 0;
    for(int i = 0; i < 26; ++i)
            if(i != s[0] - 'a')
                      f[0][1][i] = 0;
    for(int i = 1; i < n; ++i) 
            for(int j = 0; j < 200; ++j)
                for(int cur = 0; cur < 26; ++cur)
                        for(int prev = 0; prev < 26; ++prev) {
                                int inc = 0;
                                if(cur != s[i] - 'a')
                                       inc++;
                                f[i][j + inc][cur] = max(f[i][j + inc][cur], f[i - 1][j][prev] + c[prev][cur]);
                        }
    int res = - 1000 * 1000 * 1000;
    for(int i = 0; i <= k; ++i)
            for(int ch = 0; ch < 26; ++ch)
                    res = max(res, f[n - 1][i][ch]);
    
    cout << res << endl;
    
    cin >> n;
    return 0;
}