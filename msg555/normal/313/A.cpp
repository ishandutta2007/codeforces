#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <complex>

using namespace std;

int main() {
  string S; cin >> S;
  if(S[0] == '-') {
    if(S.size() == 2) {
      S = "0";
    } else {
      S = S.substr(0, S.size() - 2) + min(S[S.size() - 1], S[S.size() - 2]);
    }
    if(S == "-0") S = "0";
  }
  cout << S << endl;
  return 0;
}