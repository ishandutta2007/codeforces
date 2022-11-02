#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int a[26], n, m;
char str[100001];

bool cmp(const int &x, const int &y){
     return x > y;
}

int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     memset(a, 0, sizeof(a));
     scanf("%d%d%s", &n, &m, str);
     for (int i = 0; i < n; i++) ++a[str[i] - 'A'];
     sort(a, a + 26, cmp); 
     long long ans = 0;
     for (int i = 0; i < 26; i++)
          if (m >= a[i]) ans += 1LL * a[i] * a[i], m -= a[i];
          else ans += 1LL * m * m, m = 0;
     printf("%I64d\n", ans);
}