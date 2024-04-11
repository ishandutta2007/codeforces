#include <cstdlib>
#include <iostream>
#include <stack>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

#define wait system("pause")

const int oo = 0x3f3f3f3f;

typedef long long int64;

int64 mod;

struct Matrix{
       int64 M[2][2];
       
       Matrix operator *(const Matrix &a)
       {
              Matrix ans;
              for (int i = 0; i < 2; ++i)
              {
                  for (int j = 0; j < 2; ++j)
                  {
                      ans.M[i][j] = 0;
                      for (int k = 0; k < 2; ++k)
                      {
                          ans.M[i][j] += M[i][k] * a.M[k][j] % mod;
                          ans.M[i][j] %= mod;
                      }
                  }
              }
              return ans;
       }
};

Matrix identity()
{
       Matrix ans;
       for (int i = 0; i < 2; ++i)
       for (int j = 0; j < 2; ++j)
           ans.M[i][j] = (i == j) ? 1 : 0;
       return ans;
}

Matrix fastexp(Matrix a, int64 p)
{
       if (!p) return identity();
       Matrix ans = fastexp(a * a, p / 2);
       if (p & 1) ans = ans * a;
       return ans;            
}

int64 fib(int64 n)
{
      Matrix cur;
      cur.M[0][0] = cur.M[0][1] = cur.M[1][0] = 1;
      cur.M[1][1] = 0;
      cur = fastexp(cur, n);
      return (cur.M[0][0] + cur.M[0][1])% mod;
}

int64 modexp(int64 v, int64 p)
{
      if (!p) return 1;
      int64 ans = modexp(v * v % mod, p / 2);
      if (p & 1) ans = ans * v % mod;
      return ans;
}

int main()
{         
     int64 n, k, l, m;
     cin >> n >> k >> l >> m;
     mod = m;
     
     if (l < 63 && (k >= (1LL << l))){
           cout << 0 << endl;
           exit(0);
     }
     
     int64 ans = 1;     
     
     int64 f = fib(n);
     int64 nf = modexp(2, n) - f;
     nf = (nf % mod + mod) % mod;
          
     for (int i = 0; i < l; ++i)
     {
         if (k & (1ULL << i))
         {
             ans = ans * nf % mod;
         }
         else
         {
             ans = ans * f % mod;
         }
     }
     
     cout << ans % m << endl;
     
     //wait;
        
    return 0;
}