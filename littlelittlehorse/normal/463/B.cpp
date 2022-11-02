#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, Max;
long long ans;

int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     scanf("%d", &n); Max = 0; ans = 0;
     for (int i = 1; i <= n; i++)
     {
          int x;
          scanf("%d", &x);
          Max = max(Max, x);
     }
     printf("%d\n", Max);
}