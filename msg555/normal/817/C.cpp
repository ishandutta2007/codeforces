#include <iostream>

using namespace std;

string N;
long long pw10[20];

long long solve(long long S, int pos, bool on) {
  if (pos == N.size()) {
    return S <= 0 ? 1 : 0;
  }
  if (pw10[N.size() - pos] < S) {
    return 0;
  }
  if (S <= 0 && !on) {
    return pw10[N.size() - pos];
  }

  long long result = 0;
  for (int i = 0; i <= (on ? (int)(N[pos] - '0') : 9); i++) {
    result += solve(S - pw10[N.size() - pos - 1] * i + i,
                    pos + 1, on && '0' + i == N[pos]);
  }
  return result;
}

int main() {
  for (int i = pw10[0] = 1; i < 20; i++) {
    pw10[i] = pw10[i - 1] * 10;
  }
  pw10[19] = pw10[18];

  long long S;
  cin >> N >> S;
  cout << solve(S, 0, true) << endl;
  return 0;
}