#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int A, B; cin >> A >> B;
  int R = 0;
  while(A >= B) {
    A -= B - 1;
    R += B;
  }
  cout << A + R << endl;

  return 0;
}