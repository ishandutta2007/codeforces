#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long n;

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     cin >> n;
     int cnt = 0;
     for (; n; n /= 10)
          if ((n % 10) == 4 || (n % 10) == 7) ++cnt;
     if (cnt == 4 || cnt == 7) printf("YES\n");
     else printf("NO\n"); 
}