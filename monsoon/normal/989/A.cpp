#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110;
char s[N],z[4];

int main() {
  scanf("%s",s);
  int n = strlen(s), ok = 0;
  REP(i,n-2) {
    REP(j,3) z[j] = s[i+j];
    sort(z,z+3);
    if (strcmp(z,"ABC") == 0) ok = 1;
  }
  puts(ok ? "Yes" : "No");
}