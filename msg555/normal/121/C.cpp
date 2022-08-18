#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

vector<int> kperm(vector<int> A, int k) {
  for(int i = 0; i < A.size(); i++) {
    sort(A.begin() + i, A.end());
    int f = 1;
    for(int j = 1; j < A.size() - i; j++) f *= j;
    swap(A[i + k / f], A[i]);
    k %= f;
  }
  return A;
}

int main() {
  int N, K; cin >> N >> K;
  vector<long long> v;
  for(int i = 1; i <= 9; i++) {
    for(int j = 0; j < 1 << i; j++) {
      int x = 0;
      for(int k = 0; k < i; k++) {
        x *= 10;
        x += (j & 1 << k) ? 7 : 4;
      }
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());

  int result = 0;
  for(int i = 0; i < v.size(); i++) {
    if(v[i] + 13 <= N) {
      result++;
    } 
  }
  vector<int> vv;
  for(int i = max(N - 12, 1); i <= N; i++) {
    vv.push_back(i);
  }

  long long fcnt = 1;
  for(int i = 0; i < vv.size(); i++) fcnt *= i + 1;
  if(K > fcnt) {
    cout << "-1" << endl;
    return 0;
  }

  vv = kperm(vv, K - 1);
  for(int i = 0; i < vv.size(); i++) {
    if(binary_search(v.begin(), v.end(), max(N - 12, 1) + i) &&
       binary_search(v.begin(), v.end(), vv[i])) {
      result++;
    }
  }

  cout << result << endl;
}