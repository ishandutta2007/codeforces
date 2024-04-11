#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, M, A; cin >> N >> M >> A;
  cout << ((N + A - 1) / A) * ((M + A - 1) / A) << endl;
}