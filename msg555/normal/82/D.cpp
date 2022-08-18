#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 1000

int N;
int A[MAXN];

int memo[MAXN][MAXN];

int solve(int held, int pos) {
  if(pos == N) return A[held];
  if(pos + 1 == N) return max(A[held], A[pos]);

  int& ref = memo[held][pos];
  if(ref != -1) return ref;

  ref = max(A[held], A[pos]) + solve(pos + 1, pos + 2);
  ref = min(ref, max(A[held], A[pos + 1]) + solve(pos, pos + 2));
  ref = min(ref, max(A[pos], A[pos + 1]) + solve(held, pos + 2));
  return ref;
}

int pp;
int R[MAXN];
void recon(int held, int pos) {
  int res = solve(held, pos);
  if(pos == N) {
    R[pp++] = held;
  } else if(pos + 1 == N) {
    R[pp++] = held;
    R[pp++] = pos;
  } else if(res == max(A[held], A[pos]) + solve(pos + 1, pos + 2)) {
    R[pp++] = held;
    R[pp++] = pos;
    recon(pos + 1, pos + 2);
  } else if(res == max(A[held], A[pos + 1]) + solve(pos, pos + 2)) {
    R[pp++] = held;
    R[pp++] = pos + 1;
    recon(pos, pos + 2);
  } else if(res == max(A[pos], A[pos + 1]) + solve(held, pos + 2)) {
    R[pp++] = pos;
    R[pp++] = pos + 1;
    recon(held, pos + 2);
  }
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  memset(memo, -1, sizeof(memo));
  cout << solve(0, 1) << endl;
  pp = 0;
  recon(0, 1);
  for(int i = 0; i + 1 < N; i += 2) {
    cout << R[i] + 1 << ' ' << R[i + 1] + 1 << endl;
  }
  if(N % 2) cout << R[N - 1] + 1 << endl;
  return 0;
}