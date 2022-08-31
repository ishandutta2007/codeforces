#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <numeric>

using namespace std;

// Can make B in base A
bool can(long long A, long long B) {
  if(A % 2) {
    long long r = 0;
    while(B > 0) {
      r += B % A;
      B /= A;
    }
    return r % 2 == 0;
  } else {
    long long r = B % (A + 1);
    return r % 2 == 0;
  }
}

bool solve(long long A, long long B) {
  if(B < A) swap(A, B);
  if(A == 0) return false;
  if(!solve(B % A, A)) return true;
  if(can(A, B / A)) return true;
  return false;
}

bool solveslow(long long A, long long B) {
  if(B < A) swap(A, B);
  if(A == 0) return false;
  if(!solve(B % A, A)) return true;

  for(long long r = 1; r <= B; r *= A) {
    if(!solve(A, B - r)) {
      return true;
    }
  }
  return false;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    long long A, B; cin >> A >> B;
    cout << (solve(A, B) ? "First" : "Second") << endl;
    //cout << (solveslow(A, B) ? "First" : "Second") << endl;
  }
}