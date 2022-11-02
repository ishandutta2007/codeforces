#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int cmp(int c1[256], int c2[256]) {
    int res = 0;
    for(int i = 0; i < 256; ++i)
            if(i != int('?'))
                 res += fabs(c1[i] - c2[i]);
    return res;
}

int main() {
    string s, t;
    
    cin >> s >> t;
    
    if(t.length() > s.length()) {
                  cout << 0;
                  return 0;
    }
    
    int cs[256], ct[256], res = 0;
    
    for(int i = 0; i < 256; ++i)
            cs[i] = ct[i] = 0;
    for(int i = 0; i < t.length(); ++i)
            ct[t[i]]++;
    for(int i = 0; i < t.length(); ++i)
            cs[s[i]]++;
    if(cmp(cs, ct) <= cs['?'])
               ++res;
    for(int i = 1; i + t.length() - 1 < s.length(); ++i) {
            cs[s[i - 1]]--;
            cs[s[i + t.length() - 1]]++;
            if(cmp(cs, ct) <= cs['?'])
                       ++res;
    }
    
    cout << res;
    
    cin >> t;
    return 0;
}