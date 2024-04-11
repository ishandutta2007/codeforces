#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <map>
#include <stdlib.h>
#include <stack>
using namespace std;

const int inf = 1000 * 1000 * 1000;

int main() {
    string s;
    cin >> s;
    bool was[27][27];
    for(int i = 0; i < 27; ++i)
            for(int j = 0; j < 27; ++j)
                    was[i][j] = false;
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i) {
            char c1, c2;
            cin >> c1 >> c2;
            was[c1 - 'a' + 1][c2 - 'a' + 1] = true;
            was[c2 - 'a' + 1][c1 - 'a' + 1] = true;
    }
    int n = s.length();
    int f[n][27];
    f[0][0] = 1;
    for(int i = 1; i < 27; ++i)
            f[0][i] = inf;
    f[0][s[0] - 'a' + 1] = 0;
    for(int i = 1; i < n; ++i)
            for(int cur = 0; cur < 27; ++cur) {
                    if(cur == 0)
                           f[i][cur] = i + 1;
                    else {
                         if(cur == s[i] - 'a' + 1) { 
                                f[i][cur] = f[i - 1][0];
                                   for(int prev = 1; prev < 27; ++prev)
                                           if(was[cur][prev] == false) 
                                                                   f[i][cur] = min(f[i][cur], f[i - 1][prev]);
                         }
                         else
                             f[i][cur] = f[i - 1][cur] + 1;
                    }
            }
    int res = inf;
    for(int i = 0; i < 27; ++i)
            res = min(res, f[n - 1][i]);
    if(res == inf)
           res = n;
    cout << res;
    cin >> n;
    return 0;
}