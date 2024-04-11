#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int A[1000010];

int main() {
  string S; cin >> S;

  int id = 0;
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == 'r') {
      A[id++] = i;
    } else {
      A[id + S.size() - i - 1] = i;
    }
  }
  for(int i = 0; i < S.size(); i++) {
    cout << A[i] + 1 << endl;
  }
  return 0;
}