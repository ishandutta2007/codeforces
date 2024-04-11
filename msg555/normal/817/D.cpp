#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAXN 1000010

int A[MAXN];
int lolft[MAXN];
int lorht[MAXN];
int hilft[MAXN];
int hirht[MAXN];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    lolft[i] = i;
    while (lolft[i] && A[i] < A[lolft[i] - 1]) {
      lolft[i] = lolft[lolft[i] - 1];
    }

    hilft[i] = i;
    while (hilft[i] && A[i] > A[hilft[i] - 1]) {
      hilft[i] = hilft[hilft[i] - 1];
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    lorht[i] = i + 1;
    while (lorht[i] < N && A[i] <= A[lorht[i]]) {
      lorht[i] = lorht[lorht[i]];
    }

    hirht[i] = i + 1;
    while (hirht[i] < N && A[i] >= A[hirht[i]]) {
      hirht[i] = hirht[hirht[i]];
    }
  }

  long long result = 0;
  for (int i = 0; i < N; i++) {
    result += (1ll * (hirht[i] - i) * (i - hilft[i] + 1) -
               1ll * (lorht[i] - i) * (i - lolft[i] + 1)) *
              A[i];
  }
  cout << result << endl;

  return 0;
}