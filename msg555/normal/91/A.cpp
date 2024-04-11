#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 10000

int nxt[MAXN][26];

int main() {
  string S, T;
  cin >> S >> T;
  memset(nxt, -1, sizeof(nxt));

  int N = S.size();
  for(int i = 0; i < N; i++) {
    int j = i;
    do {
      j = (j + N - 1) % N;
      nxt[j][S[i] - 'a'] = i;
    } while(S[i] != S[j]);
  }

  int res = 0;
  int pos = N - 1;
  for(int i = 0; i < T.size(); i++) {
    int n = nxt[pos][T[i] - 'a'];
    if(n == -1) {
      puts("-1");
      return 0;
    }

    if(n <= pos) ++res;
    pos = n;
  }

  printf("%d\n", res);
}