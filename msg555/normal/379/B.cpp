#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int A[1000010];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int x = 0; x < N; x++) {
    while(A[x] > 0) {
      A[x]--;
      cout << "P";

      if(x + 1 < N) {
        cout << "R";
        if(A[x + 1]) {
          A[x + 1]--;
          cout << "P";
        }
        cout << "L";
      } else {
        cout << "LR";
      }
    }
    if(x + 1 < N) {
      cout << "R";
    }
  }
  cout << endl;

  return 0;
}