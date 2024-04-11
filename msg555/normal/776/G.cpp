#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int A[20];

long long memo[20][2][2];


long long solve(int mxdig, int x, bool on, bool hasmxdig) {
  if (x == -1) {
    return hasmxdig ? 1 : 0;
  }

  long long ref = memo[x][on ? 1 : 0][hasmxdig ? 1 : 0];
  if (ref != -1) return ref;

  ref = 0;

  int cp = on ? min(mxdig, A[x]) : mxdig;
  if ((mxdig >> 2) == x) {
    for (int i = 0; i <= cp; i++) {
      if (!(i & 1 << (mxdig & 3))) {
        continue;
      }
      ref += solve(mxdig, x - 1, on && i == A[x], hasmxdig || i == mxdig);
    }
  } else {
    if (cp > 0) ref += cp * solve(mxdig, x - 1, false, hasmxdig);
    if (cp >= 0) ref += solve(mxdig, x - 1, on && cp == A[x], hasmxdig || cp == mxdig);
  }
  return ref;
}

long long DP[20][2][2];

long long dosolve(string S, bool inclusive) {
  for (int i = 0; i < S.size(); i++) {
    if ('0' <= S[i] && S[i] <= '9') {
      A[S.size() - 1 - i] = S[i] - '0';
    } else {
      A[S.size() - 1 - i] = S[i] - 'a' + 10;
    }
  }
  if (!inclusive) A[0]--;

  long long result = 0;
  for (int mxdig = 0; mxdig < 16; mxdig++) {
    if (mxdig / 4 >= S.size()) break;

/*
    memset(memo, -1, sizeof(memo));
    result += solve(i, S.size() - 1, true, false);
*/

    for (int x = 0; x < S.size(); x++) {
      for (int on = 0; on < 2; on++) {
        for (int hasmxdig = 0; hasmxdig < 2; hasmxdig++) {
          long long& ref = DP[x + 1][on][hasmxdig];
          ref = 0;

          int cp = on ? min(mxdig, A[x]) : mxdig;
          if ((mxdig >> 2) == x) {
            for (int i = 0; i <= cp; i++) {
              if (!(i & 1 << (mxdig & 3))) {
                continue;
              }
              ref += DP[x][on && i == A[x]][hasmxdig || i == mxdig];
            }
          } else {
            if (cp > 0) ref += cp * DP[x][0][hasmxdig];
            if (cp >= 0) ref += DP[x][on && cp == A[x]][hasmxdig || cp == mxdig];
          }
        }
      }
    }
    result += DP[S.size()][1][0];
  }
  return result;
}

int main() {
  for (int i = 0; i < 20; i++) {
    DP[i][0][1] = 1;
    DP[i][1][1] = 1;
  }

  int Q; cin >> Q;

  char los[20];
  char his[20];
  for (int i = 0; i < Q; i++) {
    scanf("%s%s", los, his);
    cout << dosolve(his, true) - dosolve(los, false) << '\n';
  }
  return 0;
}