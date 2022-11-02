#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef vector<long long> lnum;
const long long base = 1000 * 1000 * 1000;

lnum mult(lnum a, int b) {
     long long carry = 0;
     for(int i = 0; i < a.size() || carry; ++i) {
             if(i == a.size())
                  a.push_back(0);
             long long cur = a[i] * b + carry;
             a[i] = cur % base;
             carry = cur / base;
     }
     return a;
}

lnum long_mult(lnum a, lnum b) {
     lnum c(a.size() + b.size());
     for(int i = 0; i < a.size() + b.size(); ++i)
             c[i] = 0;
     for(int i = 0; i < a.size(); ++i) {
             long long carry = 0;
             for(int j = 0; j < b.size() || carry; ++j) {
                     long long cur = a[i] * (j < b.size() ? b[j] : 0) + carry + c[i + j];
                     c[i + j] = cur % base;
                     carry = cur / base;
             }
     }
     while(c.size() > 1 && !c.back())
                    c.pop_back();
     return c;
}

lnum sum(lnum a, lnum b) {
     long long carry = 0;
     for(int i = 0; i < max(b.size(), a.size()) || carry; ++i) {
             if(i == a.size())
                  a.push_back(0);
             a[i] += (b.size() > i ? b[i] : 0) + carry;
             carry = a[i] / base;
             a[i] = a[i] % base;
     }
     return a;
}  

lnum short_div(lnum a, int b) {
     long long carry = 0;
     for(int i = a.size() - 1; i >= 0; --i) {
             long long cur = a[i] + carry * base;
             a[i] = cur / b;
             carry = cur % b;
     }
     while(a.size() > 1 && !a.back())
                    a.pop_back();
     return a; 
}

bool Lss(lnum a, lnum b) {
     while(a.size() > 1 && !a.back())
                    a.pop_back();
     while(b.size() > 1 && !b.back())
                    b.pop_back();
     if(a == b)
          return false;
     if(a.size() < b.size())
                 return true;
     if(a.size() > b.size())
                 return false;
     for(int i = a.size() - 1; i >= 0; --i) {
             if(a[i] > b[i])
                     return false;
             if(a[i] < b[i])
                     return true;
     }
}

lnum fact(long long n) {
     lnum res;
     res.push_back(1);
     for(int i = 2; i <= n; ++i)
             res = mult(res, i);
     return res;
}

lnum long_div(lnum a, lnum b) {
     lnum l, r = a, t;
     t.push_back(1);
     l.push_back(1);
     while(sum(l, t) != r && l != r) {
             lnum m = short_div(sum(r, l), 2); 
             if(Lss(long_mult(m, b), a) || long_mult(m, b) == a)
                             l = m;
             else
                 r = m;
     } 
     if(long_mult(r, b) == a)
                     return r;
     else
         return l;
}
     

lnum C(int n, int k) {
    return long_div(fact(n), long_mult(fact(k), fact(n - k))); 
}

int main() {
   long long n, m, t;
   lnum res;
   res.push_back(0);
   
   cin >> n >> m >> t;
   
   for(int boys = 4; boys < t; boys++) {
           int girls = t - boys;
           if(girls > m)
                    continue;
           if(boys > n)
                   continue;
           res = sum(res, long_mult(C(m, girls), C(n, boys)));
   }
   while(res.size() > 1 && !res.back())
                    res.pop_back();
   cout << res.back();
   for(int i = res.size() - 2; i >= 0; --i)
           printf("%09lld", res[i]);
   cin >> n;
   return 0; 
}