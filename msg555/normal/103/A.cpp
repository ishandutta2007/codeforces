#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  long long res = 0;
  for(int i = 1; i <= N; i++) {
    long long AI; cin >> AI;
    res += AI * i - (i - 1);
  }
  cout << res << endl;
  return 0;
}