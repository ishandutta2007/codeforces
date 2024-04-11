#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> mx(n, -1);
    string s[n];
    for(int i = 0; i < n; ++i)
            cin >> s[i];
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                    mx[j] = max(mx[j], s[i][j]);
    int res = 0;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                    if(s[i][j] == mx[j]) {
                            ++res;
                            break;
                    }
    cout << res;
    cin >> n;            
    return 0;
}