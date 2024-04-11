#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int asz;
pair<pair<long long, long long>, int> A[8];

int solve() {
  int result = asz > 1 ? 1 : 0;
  for(int i = 0; i < asz; i++) {
    result += A[i].second;
  }

  for(int i = 0; i < asz; i++) {
    for(int j = 0; j < asz; j++) {
      if(i == j) continue;
      if(A[i].first.first % A[j].first.second == 0) {
        A[i].first.first /= A[j].first.second;
        swap(A[j], A[--asz]);
        result = min(result, solve() - (A[asz].second == 0 ? 1 : 0));
        swap(A[j], A[asz++]);
        A[i].first.first *= A[j].first.second;
      }
    }
  }

  return result;
}

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> A[i].first.first;
    A[i].first.second = A[i].first.first;

    long long x = A[i].first.first;
    for(long long j = 2; j * j <= x; j++) {
      while(x % j == 0) {
        x /= j;
        A[i].second++;
      }
    }
    if(x != 1 && x != A[i].first.first) {
      A[i].second++;
    }
  }

  asz = N;
  cout << solve() + N << endl;
  return 0;
}