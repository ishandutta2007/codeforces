#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char S[50010];

int main() {
  cin >> S;
  int N = strlen(S);

  for(int sz = 1; 2 * sz <= N; sz++) {
    int i;
    int M = 0;
    int run = 0;
    char* T = S + sz;
    for(i = 0; i + sz < N; i++) {
      S[M++] = S[i];
      if(S[i] == T[i]) {
        if(++run == sz) {
          M -= sz;
          run = 0;
        }
      } else {
        run = 0;
      }
    }
    memmove(S + M, S + i, N - i);
    N += M - i;
  }

  cout << string(S, S + N) << endl;
  return 0;
}