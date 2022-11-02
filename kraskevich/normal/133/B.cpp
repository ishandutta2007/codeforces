#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int mod = 1000 * 1000 + 3;

int main() {
    int p_pow[100];
    p_pow[0] = 1;
    for(int i = 1; i < 100; ++i)
            p_pow[i] = (p_pow[i - 1] * 16) % mod;
    string s;
    
    cin >> s; 
    
    char c[256];
    
    c['>'] = 8;
    c['<'] = 9;
    c['+'] = 10;
    c['-'] = 11;
    c['.'] = 12;
    c[','] = 13;
    c['['] = 14;
    c[']'] = 15;
    
    int res = 0;
    
    for(int i = 0; i < s.length(); ++i)
            res = (res + c[s[i]] * p_pow[s.length() - i - 1]) % mod;
    
    cout << res;
    
    cin >> res;
   
    return 0;
}