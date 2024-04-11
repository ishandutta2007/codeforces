#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#include <numeric>

using namespace std;

int main() {
  int K, N; cin >> N >> K;

  long long mnv = 2000000000;
  vector<pair<long long, int> > A, B;
  for(int i = 0; i < N; i++) {
    long long x, y; cin >> x >> y;
    (y == 1 ? A : B).push_back(make_pair(x, i + 1));
    mnv = min(mnv, x);
  }
  sort(A.begin(), A.end());

  long long suma = 0;
  long long sumb = 0;
  for(int i = 0; i < A.size(); i++) suma += A[i].first;
  for(int i = 0; i < B.size(); i++) sumb += B[i].first;

  long long res = 0;
  if(K <= A.size()) {
    int piv = A.size() - K + 1;
    res = 2 * (suma + sumb) - mnv;
    for(int i = piv; i < A.size(); i++) res -= A[i].first;
    cout << (res / 2) << '.' << (res & 1 ? '5' : '0') << endl;

    for(int i = piv; i < A.size(); i++) {
      cout << "1 " << A[i].second << endl;
    }
    cout << A.size() + B.size() - K + 1;
    for(int i = 0; i < piv; i++) cout << ' ' << A[i].second;
    for(int i = 0; i < B.size(); i++) cout << ' ' << B[i].second;
    cout << endl;
  } else {
    res = suma + 2 * sumb;
    cout << (res / 2) << '.' << (res & 1 ? '5' : '0') << endl;
    for(int i = 0; i < A.size(); i++) cout << "1 " << A[i].second << endl;
    K -= A.size();
    for(int i = 0; i + 1 < K; i++) cout << "1 " << B[i].second << endl;
    cout << B.size() - K + 1;
    for(int i = K - 1; i < B.size(); i++) cout << ' ' << B[i].second;
    cout << endl;
  }
}