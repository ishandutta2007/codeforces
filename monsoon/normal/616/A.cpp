#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1000100;
char s[2][N];
int ns[2],pocz[2],ms[2];

void ret(const char* s) {
  puts(s);
  exit(0);
}

int main() {
  scanf("%s%s",s[0],s[1]);
  REP(i,2) {
    ns[i] = strlen(s[i]);
    while (pocz[i] < ns[i] && s[i][pocz[i]] == '0') ++pocz[i];
    ms[i] = ns[i]-pocz[i];
  }
  if (ms[0] > ms[1]) ret(">");
  else if (ms[0] < ms[1]) ret("<");
  else {
    REP(i,ms[0]) {
      if (s[0][pocz[0]+i] > s[1][pocz[1]+i]) ret(">");
      else if (s[0][pocz[0]+i] < s[1][pocz[1]+i]) ret("<");
    }
  }
  ret("=");
}