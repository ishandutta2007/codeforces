#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  string S;
  cin >> S;

  int cnt = 0;
  int cntlst = 0;
  vector<int> hash;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '(') {
      cnt++;
    } else {
      cnt--;
      if (S[i] == '#') {
        cntlst = cnt;
        hash.push_back(i);
      }
    }
    if (cnt < 0) {
      cout << "-1" << endl;
      return 0;
    }
  }

  int rcnt = cnt;
  cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '(') {
      cnt++;
    } else {
      cnt--;
      if (!hash.empty() && hash.back() == i) {
        cnt -= rcnt;
      }
    }
    if (cnt < 0) {
      cout << "-1" << endl;
      return 0;
    }
  }

  for (int i = 0; i + 1 < hash.size(); i++) {
    cout << "1\n";
  }
  cout << 1 + rcnt << '\n';
  return 0;
}