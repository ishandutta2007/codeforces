#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  for(int i = 0; i + 1 < N && K > 0; i++) {
    if(S[i] == '4' && S[i + 1] == '7') {
      K--;
      if(i % 2 == 0) {
        S[i + 1] = '4';
      } else {
        S[i] = '7';
        if(i > 0) {
          i--;
          if(S[i] == '4') {
            K %= 2;
          }
          i--;
        }
      }
    }
  }
  cout << S << endl;
}