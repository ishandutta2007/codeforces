#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, num;

long long check(long long now){
     long long will = 0;
     for (int i = 1; i <= n; i++) will += min(now / i, m);
     return will;
}

int main(){
   //  freopen("a.in", "r", stdin);
   //  freopen("a.out", "w", stdout);
     scanf("%d%d%I64d", &n, &m, &num);
     long long Left = 0, Right = 1LL * n * m, Mid = (Left + Right) >> 1;
     for (; Left + 1 < Right; Mid = (Left + Right) >> 1)
          if (check(Mid) < num) Left = Mid;
          else Right = Mid;
     printf("%I64d\n", Right);
}