#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100000;
int _,n,even[N],odd[N];
char s[N],z[N];

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%s",s);
    n = strlen(s);

    REP(i,n) {
      int j=1;
      while (0 <= i-j && i+j < n && s[i-j] == s[i+j]) ++j;
      odd[i] = j-1;
    }
    REP(i,n-1) {
      int j=0;
      while (0 <= i-j && i+1+j < n && s[i-j] == s[i+1+j]) ++j;
      even[i] = j;
    }

    int j = 0, ans = 0;
    while (2*j<n-1 && s[j] == s[n-1-j]) ++j;
    for (int i=j; i<=n-1-j; ++i) {
      int r = min(i-j, n-1-j-i);
      if (odd[i] >= r) ans = max(ans, 2*j+2*r+1);
    }
    for (int i=j; i<n-1-j; ++i) {
      int r = min(i-j, n-1-j-(i+1))+1;
      if (even[i] >= r) ans = max(ans, 2*j+2*r);
    }

    z[0] = 0;
    if (2*j == n) {
      strcpy(z, s);
      goto end;
    }

    for (int i=j; i<=n-1-j; ++i) {
      int r = min(i-j, n-1-j-i);
      if (odd[i] >= r) if (ans == 2*j+2*r+1) {
        strncpy(z,s,j); z[j] = 0;
        strncpy(z+j,s+i-r,2*r+1); z[j+2*r+1] = 0;
        strcpy(z+j+2*r+1,s+n-j);
        goto end;
      }
    }
    for (int i=j; i<n-1-j; ++i) {
      int r = min(i-j, n-1-j-(i+1))+1;
      if (even[i] >= r) if (ans == 2*j+2*r) {
        strncpy(z,s,j); z[j] = 0;
        strncpy(z+j,s+i-r+1,2*r); z[j+2*r] = 0;
        strcpy(z+j+2*r,s+n-j);
        goto end;
      }
    }
end:
    puts(z);
  }
}