#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int fail() {
  cout << "NO\n";
  return 0;
}

int main() {
  int N; cin >> N;

  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  char nxt[256] = {};
  bool seen[256] = {};
  bool nostart[256] = {};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < A[i].size(); j++) {
      char cha = A[i][j];
      seen[cha] = true;
      if (j > 0) {
        nostart[cha] = true;
      }

      if (j + 1 < A[i].size()) {
        char chb = A[i][j + 1];

        char& r = nxt[cha];
        if (!r) {
          r = chb;
        } else if (r != chb) {
          return fail();
        }
      }
    }
  }

  string result;
  for (int i = 0; i < 256; i++) {
    if (seen[i] && !nostart[i]) {
      for (char ch = i; ch; ch = nxt[ch]) {
        if (!seen[ch]) {
          return fail();
        }
        seen[ch] = false;
        result += ch;
      }
    }
  }
  for (int i = 0; i < 256; i++) {
    if (seen[i]) {
      return fail();
    }
  }
  cout << result << endl;

  return 0;
}