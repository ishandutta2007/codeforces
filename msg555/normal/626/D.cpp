#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 2020
#define MAXV 5010

long long N;
int A[MAXN];
int tr[MAXV];

long long memo[3][2][4 * MAXV];

long long solve(int round, int wins, int diff) {
  if (wins > 1) {
    return 0;
  }
  if (round == 3) {
    return wins == 1 && diff > 0 ? 1 : 0;
  }

  long long& ref = memo[round][wins][diff + 2 * MAXV];
  if (ref != -1) return ref;

  ref = 0;
  for (int i = 1; i < MAXV; i++) {
    ref += tr[i] * solve(round + 1, wins + 1, diff + i);
    ref += tr[i] * solve(round + 1, wins, diff - i);
  }

  return ref;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A + N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      tr[A[i] - A[j]]++;
    }
  }


  double num = N * (N - 1) / 2;
  num = num * num * num * 3;

  memset(memo, -1, sizeof(memo));
  cout << 1.0 * solve(0, 0, 0) / num << endl;
  
  return 0;
}