#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int len;
string buf;
long long memo[60][60][2];

long long go(int idig, int x, bool on) {
  if(x == len) return 1;

  long long& res = memo[idig][x][on];
  if(res != -1) return res;
  res = 0;
  for(int i = 0; i < 10; i++) {
    if(x + 1 == len && i != idig) continue;
    if(on && i > buf[x] - '0') continue;
    res += go(idig, x + 1, on && i == buf[x] - '0');
  }
  return res;
}

long long solve(long long x) {
  ostringstream sout;
  sout << x;
  buf = sout.str();
  long long sum = 0;
  len = buf.size();
  memset(memo, -1, sizeof(memo));
  for(int i = 1; i < 10; i++) {
    for(int j = 1; j <= len; j++) {
      if(j == len && i > buf[0] - '0') continue;
      sum += go(i, len - j + 1, j == len && i == buf[0] - '0');
    }
  }
  return sum;
}

int main() {
  long long a, b; cin >> a >> b;
  cout << solve(b) - solve(a - 1) << endl;
}