#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;

  int cnt = 0;
  for (int i = 1; i < N; i++) {
    if (S[i] == S[i - 1]) {
      cnt++;
    }
  }
  cout << (N - cnt) + min(cnt, 2) << endl;
  return 0;
}