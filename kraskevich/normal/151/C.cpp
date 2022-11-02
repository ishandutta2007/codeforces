#include <iostream>
#include <vector>
using namespace std;

bool prime(long long n) {
     for(long long i = 2; i * i <= n; ++i)
              if(n % i == 0)
                   return false;
     return true;
}

int main() {
    long long q;
    cin >> q;
    if(q == 1 || prime(q)) {
              cout << 1 << endl << 0;
              return 0;
    }     
    vector<long long> div;
    long long cur = q, t = 2;
    while(t * t <= q && cur) {
            if(cur % t == 0 && prime(t)) {
                 while(cur % t == 0) {
                           cur /= t;
                           div.push_back(t);
                 }
            }
            if(div.size() > 2)
                          break;
            ++t;
    }
    if(cur != 1 && div.size() <= 2)
           div.push_back(cur);
    if(div.size() <= 2) {
           cout << 2;
           cin >> q;
           return 0;
    }
    else
        cout << 1 << endl << div[0] * div[1];
     cin >> q;
     return 0;                        
}