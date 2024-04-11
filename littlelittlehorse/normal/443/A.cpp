#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

char str[1001];
bool b[26];
int n;

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     gets(str); n = strlen(str);
     memset(b, false, sizeof(b));
     for (int i = 0; i < n; i++) 
          if (str[i] >= 'a' && str[i] <= 'z')
               b[str[i] - 'a'] = true;
     int ans = 0;
     for (int i = 0; i < 26; i++) ans += b[i];
     printf("%d\n", ans);
}