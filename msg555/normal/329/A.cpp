#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

string A[110];
bool cn[210][210];
bool vis[210];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool e1 = false;
  bool e2 = false;
  for(int i = 0; i < N; i++) {
    int ce1 = 0, ce2 = 0;
    for(int j = 0; j < N; j++) {
      if(A[i][j] == 'E') {
        ce1++;
      }
      if(A[j][i] == 'E') {
        ce2++;
      }
    }
    e1 |= ce1 == N;
    e2 |= ce2 == N;
  }
  if(e1 && e2) {
    cout << "-1" << endl;
    return 0;
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(e1) {
        if(A[j][i] != 'E') {
          cout << j + 1 << ' ' << i + 1 << endl;
          break;
        }
      } else {
        if(A[i][j] != 'E') {
          cout << i + 1 << ' ' << j + 1 << endl;
          break;
        }
      }
    }
  }

  return 0;
}