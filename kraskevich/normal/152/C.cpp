#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cstdio>
using namespace std;

const long long base = 1000 * 1000 * 1000 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; ++i)
            cin >> s[i];
    bool was[m][26];
    for(int i = 0; i < m; ++i)
            for(int j = 0; j < 26; ++j)
                    was[i][j] = false;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                    was[j][s[i][j] - 'A'] = true;
    long long res = 1;
    for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < 26; ++j)
                    cnt += (was[i][j] ? 1 : 0);
            res = (res * cnt) % base;
    }
    cout << res % base;
    cin >> n;
    return 0;        
}