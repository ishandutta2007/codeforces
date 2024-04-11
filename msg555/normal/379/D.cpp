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

int K, X, N, M;

char FF[60];
char FL[60];
int FC[60];

bool check(string s1, string s2) {
  FF[0] = s1[0];
  FL[0] = s1[N - 1];
  FC[0] = 0;
  for(int i = 0; i + 1 < N; i++) {
    if(s1[i] == 'A' && s1[i + 1] == 'C') {
      FC[0]++;
    }
  }
  FF[1] = s2[0];
  FL[1] = s2[M - 1];
  FC[1] = 0;
  for(int i = 0; i + 1 < M; i++) {
    if(s2[i] == 'A' && s2[i + 1] == 'C') {
      FC[1]++;
    }
  }

  for(int i = 2; i < K; i++) {
    FF[i] = FF[i - 2];
    FL[i] = FL[i - 1];
    FC[i] = FC[i - 1] + FC[i - 2];
    if(FL[i - 2] == 'A' && FF[i - 1] == 'C') {
      FC[i]++;
    }
    if(FC[i] > X) {
      return false;
    }
  }
  return FC[K - 1] == X;
}

int main() {
  cin >> K >> X >> N >> M;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      string s1(N, 'Z');
      string s2(M, 'Z');
      if(i & 1) s1[0] = 'C';
      if(i & 2) s1[N - 1] = 'A';
      if(j & 1) s2[0] = 'C';
      if(j & 2) s2[M - 1] = 'A';
      string t2 = s2;
      for(int x = i & 1; ; x += 2) {
        s2 = t2;
        for(int y = j & 1; ; y += 2) {
          if(check(s1, s2)) {
            cout << s1 << endl;
            cout << s2 << endl;
            return 0;
          }
          if(y + 2 > M - (j & 2 ? 1 : 0)) break;
          s2[y] = 'A';
          s2[y + 1] = 'C';
        }
        if(x + 2 > N - (i & 2 ? 1 : 0)) break;
        s1[x] = 'A';
        s1[x + 1] = 'C';
      }
    }
  }
  
  cout << "Happy new year!" << endl;
  return 0;
}