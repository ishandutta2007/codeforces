#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110000;
int n;
char s[N];
pair<int,string> ans;

void tryit(int p) {
  string z;
  int r=0;
  REP(i,max(p,n-p)) {
    int dig = r + (i<p ? s[i]-'0' : 0) + (i+p<n ? s[i+p] - '0' : 0);
    z += char(dig%10 + '0');
    r = dig/=10;
  }
  if (r) { z += char(r + '0'); }
  reverse(z.begin(), z.end());
  ans = min(ans, make_pair(int(z.size()), z));
}

int main() {
  scanf("%d%s",&n,s);
  reverse(s,s+n);
  ans = make_pair(4*n, "");

  int p=n/2;
  while (p>0 && s[p-1] == '0') --p;
  if (p>0) tryit(p);
  --p; while (p>0 && s[p-1] == '0') --p;
  if (p>0) tryit(p);
  p=n/2+1;
  while (p<n && s[p-1] == '0') ++p;
  if (p<n) tryit(p);
  ++p; while (p<n && s[p-1] == '0') ++p;
  if (p<n) tryit(p);

  printf("%s\n", ans.second.c_str());
}