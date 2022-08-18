#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int GG[] = {-1, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
bool vis[100000];

map<int, int> memo;

/*
int grundy(int m) {
  if(memo.find(m) != memo.end()) return memo[m];

  vector<bool> C(32, false);
  for(int i = 0; i < 30; i++) {
    if(m & 1 << i) {
      int mm = m;
      for(int j = i; j < 30; j += i + 1) {
        mm &= ~(1 << j);
      }
      C[grundy(mm)] = true;
    }
  }
  for(int i = 0; i < 32; i++) {
    if(!C[i]) {
      return memo[m] = i;
    }
  }
  return -1;
}
*/

int main() {
  int N;
  cin >> N;

/*
  for(int i = 1; i < 30; i++) {
    GG[i] = grundy((1 << i) - 1);
cout << GG[i] << ", ";
  }
cout << endl;
*/

  int G = N & 1;
  for(int i = 2; i * i <= N; i++) {
    if(!vis[i]) {
      int cnt = 0;
      for(long long x = i; x <= N; x *= i) {
        G ^= 1;
        if(x * x <= N) {
          vis[x] = true;
        }
        cnt++;
      }
      G ^= GG[cnt];

      vis[i] = true;
    }
  }
  cout << (G ? "Vasya" : "Petya") << endl;

  return 0;
}