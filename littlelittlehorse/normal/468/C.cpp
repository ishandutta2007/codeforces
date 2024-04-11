#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long a, n;

int main(){
   //  freopen("c.in", "r", stdin);
   //  freopen("c.out", "w", stdout);
     scanf("%I64d", &n);
     a = 45 % n; a *= 18; a %= n;
     for (int i = 1; i < 18; i++)
          a *= 10, a %= n;
     printf("%I64d %I64d\n", n - a, n - a + 1000000000000000000LL - 1);
}