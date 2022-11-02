#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, ans;

int main(){
    // freopen("a.in", "r", stdin);
   //  freopen("a.out", "w", stdout);
     ans = 0;
     scanf("%d%d%d", &a, &b, &c);
     ans = max(ans, a + b + c);
     ans = max(ans, a * b + c);
     ans = max(ans, a * (b + c));
     ans = max(ans, a + b * c);
     ans = max(ans, (a + b) * c);
     ans = max(ans, a * b * c);
     printf("%d\n", ans);
}