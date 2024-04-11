#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ZERO(v) memset(v, 0, sizeof v)

const int INF = INT_MAX/4;
int len;
string commands;

bool been[105][55][2];
int memo[105][55][2];

int calc(int p, int n, int dir) {
  if (p == len) {
    return n%2 == 0 ? 0 : -INF;
  }

  int &res = memo[p][n][dir > 0];
  if (been[p][n][dir > 0]) {
    return res;
  }
  
  been[p][n][dir > 0] = 1;
  res = -INF;
  for (int toggle=0; toggle<2; ++toggle) {
    if (n == 0 && toggle) {
      continue;
    }

    int command = commands[p];
    if (toggle) {
      command = command == 'T' ? 'F' : 'T';
    }

    if (command == 'F') {
      res = max(res, dir + calc(p+1, n-toggle, dir));
    } else {
      res = max(res, calc(p+1, n-toggle, -dir));
    }
  }
  return res;
}

int main() {
  cin.sync_with_stdio(0);

  cin >> commands;
  len = (int)commands.size();

  int n;
  cin >> n;
  ZERO(been);
  cout << max(calc(0, n, 1), calc(0, n, -1)) << "\n";

  return 0;
}