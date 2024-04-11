#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;

  int st = 0;
  int m10 = 0;
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '?') {
      m10++;
    } else if('A' <= S[i] && S[i] <= 'J') {
      
      st |= 1 << (S[i] - 'A');
    }
  }

  long long res = 1;
  for(int i = 0; i < __builtin_popcount(st); i++) {
    res *= 10 - i;
  }
  if(S[0] == '?') {
    m10--;
    res *= 9;
  } else if('A' <= S[0] && S[0] <= 'J') {
    res = res / 10 * 9;
  }

  cout << res << string(m10, '0') << endl;
  return 0;
}