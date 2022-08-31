#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

long long A[100010];
long long B[100010];

#define INFX 1000000009LL
#define INF (INFX*INFX)

long long exceed(pair<long long, long long> a, pair<long long, long long> b) {
  return (b.second - a.second + (a.first - b.first - 1)) / (a.first - b.first);
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> B[i];
  }
  if(N == 1) {
    cout << "0" << endl;
    return 0;
  }

  int c0 = 0;
  vector<pair<long long, long long> > C;
  C.push_back(make_pair(A[N - 1], 0));
  for(int i = N - 2; i >= 0; i--) {
    for(; c0 + 1 < C.size();) {
      pair<long long, long long> a = C[c0];
      pair<long long, long long> b = C[c0 + 1];
      //if(a.first * B[i] + a.second >= b.first * B[i] + b.second) {
      if(a.first - b.first >= (b.second - a.second + B[i] - 1) / B[i]) {
        c0++;
      } else {
        break;
      }

    }

    long long val = min(INF, C[c0].first * B[i] + C[c0].second);

    pair<long long, long long> v = make_pair(A[i], val);
    while(C.size() - c0 > 1) {
      pair<long long, long long> a = C[C.size() - 1];
      pair<long long, long long> b = C[C.size() - 2];
      if(exceed(a, v) <= exceed(a, b)) {
        C.resize(C.size() - 1);
      } else {
        break;
      }
    }
    C.push_back(v);

    if(i == 0) {
      cout << val << endl;
    }
  }

  return 0;
}