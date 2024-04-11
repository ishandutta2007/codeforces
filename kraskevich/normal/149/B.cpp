#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

long long dg(char c) {
     if(c >= '0' && c <= '9')
          return int(c - '0');
     else
         return (int)c - 'A' + 10;
}

long long conv(string s, long long pos) {
     long long p_pow = 1, res = 0;
     for(int i = s.length() - 1; i >= 0; --i) {
             if(dg(s[i]) >= pos)
                         return -1;
             res += p_pow * dg(s[i]);
             p_pow *= pos;
     }
     return res;
}

int main() {
    string s;
    
    cin >> s;
    
    string h = "", m = "";
    
    int i = 0;
    
    while(s[i] != ':') {
               h += s[i];
               ++i;
    }
    i++;
    while(i < s.length()) {
            m += s[i];
            ++i;
    }
    
    int cnt = 0;
    
    int start = 2;
    
    for(int j = 0; j < s.length(); ++j) {
            if(s[j] == ':')
                    continue;
            else
                start = max((long long)start, dg(s[j]) + 1);
    }
    
    for(int j = start; j <= 1000; ++j) {
            long long H = conv(h, j), M = conv(m, j);
            if(H >= 0 && M >= 0 && H <= 23 && M <= 59)
                 cnt++;
    }
    
    if(cnt == 0) {
           cout << 0;
           cin >> s;
           return 0;
    }
    
    if(cnt == 1000 - start + 1) {
           cout << -1;
           cin >> s;
           return 0;
    }
    
    for(int j = start; j <= 1000; ++j) {
            long long H = conv(h, j), M = conv(m, j);
            if(H >= 0 && M >= 0 && H <= 23 && M <= 59)
                 cout << j << " ";
    }
    
    cin >> s;
    
    return 0;
}