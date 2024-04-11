#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long A, B;
const int P = 1000000007;

long long rp(long long now, int k){
     long long will = 1;
     for (; k; k >>= 1, now *= now, now %= P) 
          if (k & 1) will *= now, will %= P;
     return will;
}

int main(){
   //  freopen("a.in", "r", stdin);
   //  freopen("a.out", "w", stdout);
     scanf("%I64d%I64d", &A, &B);
     long long ans = 2 * A * B % P * (B - 1) % P
      + (A + 1) * A % P * B % P * B % P * (B - 1) % P;
     ans %= P;
     printf("%d\n", ans * rp(4, P - 2) % P); 
}