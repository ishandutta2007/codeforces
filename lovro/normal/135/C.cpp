#include <cassert>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

void solve(string str, set<string> &out) {
  int len = str.size();
  assert(str[len-1] != '?');
  
  int n0 = 0, n1 = 0, nq = 0;
  foreach (it, str) {
    if (*it == '0') ++n0;
    else if (*it == '1') ++n1;
    else ++nq;
  }

  int a = (len+1)/2 - 1, b = len/2 - 1;

  if (n0+nq - b > n1 - a) {
    out.insert("00");
  }
  if (n1+nq - a > n0 - b) {
    out.insert("11");
  }

  int gap = abs((n0-b) - (n1-a));
  if (gap <= nq) {
    if (str[len-1] == '1') {
      out.insert("01");
    }
    if (str[len-1] == '0') {
      out.insert("10");
    }
  }
}

int main() {
  cin.sync_with_stdio(0);

  string str;
  cin >> str;

  int len = str.size();
  set<string> out;
  if (str[len-1] == '?') {
    str[len-1] = '0'; solve(str, out);
    str[len-1] = '1'; solve(str, out);
  } else {
    solve(str, out);
  }
  
  foreach (it, out) {
    cout << *it << '\n';
  }

  return 0;
}