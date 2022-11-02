#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <list>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define forn for(int i = 0; i < n; ++i)

string s[1000000];
const int inf = 1000 * 1000 * 1000;
int f[26];

void init()
{
     for(int i = 0; i < 26; ++i)
             f[i] = -inf;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    forn cin >> s[i];
    
    int ans = 0;
    for(int frs = 0; frs < 'z' - 'a' + 1; ++frs)
    {
             init();
             int cur = 0;
             for(int i = 0; i < n; ++i)
             {
                     int c = (int)s[i][0] - (int)'a', l = (int)s[i][s[i].length() - 1] - (int)'a';
                     int prevc = f[c];
                     if(c == frs)
                          f[l] = max(f[l], (int)s[i].length());
                     f[l] = max(f[l], prevc + (int)s[i].length());
                     if(l == frs)
                          cur = max(cur, prevc + (int)s[i].length());
                     if(l == frs && c == frs)
                          cur = max(cur, (int)s[i].length());
             }
             ans = max(ans, cur);
    }
    
    cout << ans;
    
    cin >> n;         
    return 0;
}