#include <iostream>
#include <string>
using namespace std;

bool bit(int mask, int n) {
    return ((mask & (1 << n)) ? 1 : 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    string patt[8];
    for(int i = 0; i < 8; ++i)
            cin >> patt[i];
    int n = 8, res = 1000;
    for(int mask = 0; mask < (1 << 16); ++mask) {
            string s[8];
            for(int i = 0; i < 8; ++i)
                    s[i] = "WWWWWWWW";
            int cur = 0;
            for(int i = 0; i < 8; ++i) 
                    if(bit(mask, i)) {
                                 ++cur;
                                 for(int j = 0; j < n; ++j)
                                         s[i][j] = 'B';
                    }
            for(int i = 8; i < 16; ++i) 
                    if(bit(mask, i)) {
                                 ++cur;
                                 for(int j = 0; j < n; ++j)
                                         s[j][i - 8] = 'B';
                    }
            bool ok = true;
            for(int i = 0; i < n; ++i)
                    for(int j = 0; j < n; ++j)
                            if(s[i][j] != patt[i][j])
                                       ok = false;
            if(ok)
                  res = min(res, cur);
    }
    cout << res;
    return 0;
}