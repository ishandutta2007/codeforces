#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int sell = 0, win = 1;
const long long base = 1000 * 1000 * 1000;

typedef vector<long long> lnum;

lnum x2(lnum a) {
     long long carry = 0;
     for(int i = 0; i < a.size() || carry; ++i) {
             if(i == a.size())
                  a.push_back(0);
             long long cur = a[i] * 2 + carry;
             a[i] = cur % base;
             carry = cur / base;
     }
     return a;
}

lnum sum(lnum a, lnum b) {
     long long carry = 0;
     for(int i = 0; i < max(a.size(), b.size()) || carry; ++i) {
             if(i == a.size())
                  a.push_back(0);
             a[i] += carry + (i < b.size() ? b[i] : 0);
             carry = a[i] / base;
             a[i] = a[i] % base;
     }
     return a;
}

lnum mx(lnum a, lnum b) {
     if(a.size() < b.size())
                 return b;
     if(a.size() > b.size())
                 return a;
     for(int i = a.size() - 1; i >= 0; --i) {
             if(a[i] > b[i])
                     return a;
             if(b[i] > a[i])
                     return b;
     }
     return a;
}

int main() {
    lnum p_pow[2001];
    p_pow[0].push_back(1);
    for(int i = 1; i <= 2000; ++i)
            p_pow[i] = x2(p_pow[i - 1]);
    int n;
    
    cin >> n;
    
    int x[n], type[n];
    
    for(int i = 0; i < n; ++i) {
            string s;
            int X;
            cin >> s >> X;
            x[i] = X; 
            if(s == "sell") 
                 type[i] = sell;
            else
                type[i] = win;
    }
    
    lnum f[n];
    
    f[0].push_back(0);
    
    for(int i = 0; i < n; ++i) {
            if(type[i] == win && i)
                       f[i] = f[i - 1];
            else  {
                 if(i)
                       f[i] = f[i - 1];
                 for(int j = 0; j < i; ++j) 
                         if(type[j] == win && x[j] == x[i])
                                    f[i] = mx(f[i], sum(f[j], p_pow[x[i]]));
            }
    }
    cout << f[n - 1].back();
    for(int i = f[n - 1].size() - 2; i >= 0; --i)
            printf("%09lld", f[n - 1][i]);
    cin >> n;
    return 0;           
}